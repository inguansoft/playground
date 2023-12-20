import random
MATCH = 0
BIG = 1
BIGER = 2
TOO_BIG = 3
SMALL = 4
SMALLER = 5
TOO_SMALL = 6
magic_number = 0
def validate_input(from_aa, to_bb):
    valid = from_aa < to_bb
    if valid:
        print("Good interval ", end='')
    else:
        print("Not a valid interval ", end='')
    print("from ", from_aa, " to ", to_bb)
    return valid

def test_magic_number(from_aa, to_bb, try_number_x):
    return BIG


from_a = 0
to_b = 0
while not validate_input(from_a, to_b):
    from_a = input('Enter from number: ')
    to_b = input('Enter to number: ')

magic_number = random.randint(from_a, to_b)

try_number = magic_number + 1
while (test_magic_number(from_aa, to_bb, try_number_x) != MATCH):
    try_number= input('Try number: ')