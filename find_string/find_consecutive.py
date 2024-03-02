input_string = "abbdfghhhhhhkjkjkjkjkjkkkkkkkj"

prev = ''
top = ''
count = 0
max = 0
for x in input_string:
    if prev == x:
        count += 1
        if count > max:
            max = count
            top = x
    else:
        count = 1
    prev=x
print(f"From {input_string} we found the longest consecutive repeated string:")
print(f"-{top*max}- ")
