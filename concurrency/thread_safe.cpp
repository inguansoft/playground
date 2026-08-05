#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <vector>
#include <memory>

class SafeDataPipeline {
private:
    mutable std::mutex realTimeMtx;
    std::vector<double> realTimeBuffer;

    mutable std::shared_mutex historyMtx;
    std::vector<double> historicalData;

    std::atomic<bool> isProcessing{false};

public:
    // 1. Preventing Data Races with std::lock_guard (RAII)
    void pushRealTimeData(double value) {
        std::lock_guard<std::mutex> lock(realTimeMtx);
        realTimeBuffer.push_back(value);
    }

    // 2. Optimizing Historical Reads with Shared Locks
    double getHistoricalAverage() const {
        std::shared_lock<std::shared_mutex> lock(historyMtx);
        if (historicalData.empty()) return 0.0;
        
        double sum = 0.0;
        for (const auto& val : historicalData) {
            sum += val;
        }
        return sum / historicalData.size();
    }

    // 3. Atomically signaling state without mutex overhead
    bool checkStatus() const {
        return isProcessing.load(std::memory_order_acquire);
    }
};




int main() {
    SafeDataPipeline pipeline;

    // Simulate real-time data push
    pipeline.pushRealTimeData(1.0);
    pipeline.pushRealTimeData(2.0);

    // Simulate historical data read
    double average = pipeline.getHistoricalAverage();
    std::cout << "Historical Average: " << average << std::endl;

    // Check processing status
    bool status = pipeline.checkStatus();
    std::cout << "Is Processing: " << std::boolalpha << status << std::endl;

    return 0;
}