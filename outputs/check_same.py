from os.path import isfile
import sys


def check_files(file_1, file_2):
  # Make sure the inputed files are valid
  if not isfile(file_1):
    print(file_1, "could not be found")
    return
  if not isfile(file_2):
    print(file_2, "could not be found")
    return
  
  # Check each file's bytes
  with open(file_1, 'rb') as file1, open(file_2, 'rb') as file2:
    if file1.read() == file2.read():
      print("Files are the same")
    else:
      print("Files are different")

if __name__ == "__main__":
  if len(sys.argv) < 3:
    print("Too few arguments")
  else:
    check_files(*sys.argv[1:3])
