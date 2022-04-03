import math
# Add any extra import statements you may need here
from collections import Counter

# Add any helper functions you may need here


#arr is a list of arrays and im returning and integer 
def countDistinctTriangles(arr):
  # Write your code here
  # Here it doesnt matter the order of the values in the arrays, just the values 
  # arr = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
  # 2, 2, 3] = [3, 2, 2] same triangle

  triangles = set()  # to store multiple items in the same variable with NO REPETITION
  #create a dictionary for each element of the array
  for t in arr:
    triangles.add(tuple(sorted(t))) 
    # sorted will return a LIST [] so i add the tuple and add it to the set
    
  return len(triangles)

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
  arr_1 = [(7, 6, 5), (5, 7, 6), (8, 2, 9), (2, 3, 4), (2, 4, 3)]
  expected_1 = 3
  output_1 = countDistinctTriangles(arr_1)
  check(expected_1, output_1)

  arr_2 = [(3, 4, 5), (8, 8, 9), (7, 7, 7)]
  expected_2 = 3
  output_2 = countDistinctTriangles(arr_2)
  check(expected_2, output_2)

  # Add your own test cases here
  
