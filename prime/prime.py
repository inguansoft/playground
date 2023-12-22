
def process_prime_list(number):
    results = []
    i = number
    while i > 1:
        j=i - 1
        while j > 1:
            if i%j == 0:
                break
            j-=1
        if j == 1:
            results.append(i)
        i-=1
        
    return results

def valid_input(number):
    return number > 0

input_number = 1
while (input_number != 0):
    try:
        user_input = input("Prime numbers from 2 to N (0 to exit) N=").replace(' ','')
        input_number = int(user_input)
    except:
        print("Expected a valid integer number, please try again!")
        continue
    if valid_input(input_number):
        prime_list = process_prime_list(input_number)
        print (f"Calculated {prime_list}")
    else:
        if(input_number == 0):
            print("Bye")
        else:
            print("Expected input > 0, please try again.")