
def print_pattern(num_param):
  j = num_param
  if 0 < num_param < 40:
    while j > 0: # reps
      i = j
      while i > 0:
        print ((str(i) + " ") * j, end='')
        i -= 1
      print("$", end='')
      j -= 1
    print("\nSuccessfully process sequence : " + str(num_param))
  else:
    print("Error, expecting 1..40 but got:" + str(num_param))

LIMIT = 5

#number = -2
for number in range(-2, 5):
#while number <= LIMIT:
  print_pattern(number)
  #number += 1