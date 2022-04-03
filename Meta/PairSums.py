import math
# Add any extra import statements you may need here
from collections import Counter

## TO CHECK: 
# https://www.geeksforgeeks.org/count-pairs-with-given-sum/


# Add any helper functions you may need here
# this is not the solution
def numberOfWays2(arr, k):
  # solution with O(n^2)
  amount = 0
  n = len(arr)
  for i in range(0,n):
    for j in range(0,n):
      if arr[i] + arr[j] == k: # i am not checking if they are different!
        amount += 1
  return amount

# CORRECT ONE USING DICTIONARY 
def numberOfWays(arr, k):
   # Write your code here
   ## things to consider: arr is in order?
  # I create a dictionary to map the index of the array with the values
  d = Counter(arr)
  amount = 0
  
  for key in d:
      if k - key == key:
        value = d[key]
        amount += value * (value - 1) / 2  
      else:
        amount += d[key] * d[k - key] / 2 # I DONT GET THE REPEATED ONES
  return amount


# These are the tests we use to determine if the solution is correct.
# You can add your own at the bottom.

def printInteger(n):
  print('[', n, ']', sep='', end='')

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
    printInteger(expected)
    print(' Your output: ', end='')
    printInteger(output)
    print()
  test_case_number += 1

if __name__ == "__main__":
  k_1 = 6
  arr_1 = [1, 2, 3, 4, 3]
  expected_1 = 2
  output_1 = numberOfWays(arr_1, k_1)
  check(expected_1, output_1)

  k_2 = 6
  arr_2 = [1, 5, 3, 3, 3]
  expected_2 = 4
  output_2 = numberOfWays(arr_2, k_2)
  check(expected_2, output_2)

  # Add your own test cases here
  