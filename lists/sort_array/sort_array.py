import random

array = {};
for i in range(0, 100):
    array[i] = random.randint(0, 100)

print("Unsorter array")
print(array)

for i in range(0, 100):
    current = array[i]
    inject = -1
    for j in range(0, i+1):
        if inject > -1 or current < array[j]:
            inject += 1
            if i - inject > 0:
                array[i - inject] = array[i - inject - 1]
    if inject != -1:
        array[i - inject] = current

print("Sorter array")
print(array)