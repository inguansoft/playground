# Make a function to remove the repeated continuous 
# characters from a string.

def remove_continnuous_repeated_charcaters(input_string):
    new_string = ''
    prev = ''
    i = len(input_string)-1
    if i < 1:
        return input_string
    while(i>=0):
        if i == 0:
            if input_string[i] != input_string[i+1]:
                new_string = input_string[i] + new_string
        else:
            if i == len(input_string)-1:
                if input_string[i] != input_string[i-1]:
                    new_string = input_string[i] + new_string
            else:
                if input_string[i] != input_string[i-1] \
                    and input_string[i] != input_string[i+1]:
                    new_string = input_string[i] + new_string
        i -= 1
    return new_string

input_param = "abbdfghhhhhhkjkjkjkjkjkkkkkkkj"
print(f"{input_param}")
print(f"-{remove_continnuous_repeated_charcaters(input_param)}- ")

input_param = "a"
print(f"{input_param}")
print(f"-{remove_continnuous_repeated_charcaters(input_param)}- ")

input_param = "aa"
print(f"{input_param}")
print(f"-{remove_continnuous_repeated_charcaters(input_param)}- ")
