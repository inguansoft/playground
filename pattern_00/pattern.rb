# @param [Integer] num_param
# @return [nil]
def print_pattern (num_param)
  j = num_param
  if num_param > 0 and num_param < 40
    while j > 0 # reps
      i = j
      while i > 0
        print (i.to_s + " ") * j
        i -= 1
      end
      print("$")
      j -= 1
    end
    puts("\nSuccessfully process sequence : " + num_param.to_s)
  else
    puts("Error, expecting 1..40 but got:" + num_param.to_s)
  end
end


(-2..5).each do |number|
  print_pattern(number)
end
