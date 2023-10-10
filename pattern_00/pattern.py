
def print_pattern(number):
  j = number
  if number > 0 and number < 40:
    while j > 0: # reps
      i = j
      while i > 0:
        print ((str(i) + " ") * j, end='')
        i -= 1
      print("$", end='')
      j -= 1
    print("\nSuccessfully process sequence : " + str(number))
  else:
    print("Error, expecting number from 1 to 40")

LIMIT = 5

number = 0
while number <= LIMIT:
  print_pattern(number)
  number += 1