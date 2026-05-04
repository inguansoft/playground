

#include <stdint.h>

void transfer_data(void *blob, uint32_t len, uint32_t bucket_size) {
    uint32_t offset = 0;
    while (offset < len) {
        uint32_t chunk_size = (len - offset < bucket_size) ? (len - offset) : bucket_size;
        tcp_send(blob + offset, chunk_size); // Assume tcp_send is defined elsewhere to send data over TCP
        // Simulate data transfer for the current chunk
        // For example, you could write the chunk to a file or send it over a network
        // Here, we just print the chunk size for demonstration purposes
        printf("Transferring chunk of size: %u bytes\n", chunk_size);
        offset += chunk_size;
    }
}

int main() {
    uint32_t len = 100, bucket_size = 16;
    void *blob = malloc(len);
    transfer_data(blob, len, bucket_size);
    free(blob);
}