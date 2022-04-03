import math
# Add any extra import statements you may need here


# Add any helper functions you may need here


def balancedSplitExists(arr):
  #  [1, 5, 7, 1]
  arr.sort()
  #  [1, 1, 5, 7]
  # i have to split that array and
    # check if every number is smaller
    # check if the total sum of each side is the same
  # so not very efficient... lets create a acumulative sum array 
  arr_summed = arr.copy()
  
  for i in range(1, len(arr_summed)):
    arr_summed[i] += arr_summed[i-1]
     # 1+1 = 2, 1+1+5=7, 1+1+5+7 = 14
     #  [1, 2, 7, 14]
    # benefit? i can check if 7 = 14/2
    # the other example: [12, 7, 6, 7, 6] -> [6, 12, 19, 26, 38] is 19 = 38/2?
    # last one is with -1 index
  for i in range(0,len(arr_summed) - 1):
    if arr_summed[i] == arr_summed[-1]/2 and arr[i] != arr[i+1]:
      return True
  return False
      
  

  










# These are the tests we use to determine if the solution is correct.
# You can add your own at the bottom.

def printString(string):
  print('[\"', string, '\"]', sep='', end='')

test_case_number = 1

def check(expected, output):
  global test_case_number
  result = False
  if expected == output:
    result = True
  rightTick = '\u2713'
  wrongTick = '\u2717'
  if result:
    print(rightTick, 'Test #', test_case_number, sep='')
  else:
    print(wrongTick, 'Test #', test_case_number, ': Expected ', sep='', end='')
    printString(expected)
    print(' Your output: ', end='')
    printString(output)
    print()
  test_case_number += 1

if __name__ == "__main__":
  arr_1 = [2, 1, 2, 5]
  expected_1 = True
  output_1 = balancedSplitExists(arr_1)
  check(expected_1, output_1)

  arr_2 = [3, 6, 3, 4, 4]
  expected_2 = False
  output_2 = balancedSplitExists(arr_2)
  check(expected_2, output_2)

  # Add your own test cases here
  