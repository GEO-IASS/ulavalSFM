
### micro-program to clean the directory before running ulavalSFM

#!/usr/bin/python
### micro-program to check if there is png files among the jpg

#USAGE# 
# cleanSFM.py

import os
 
os.system("ext.sh .JPG .jpg")
 
a = "./" 
b = os.listdir(a)
 
for i in b:
	ext = i[len(i)-3:len(i)]
	if ext == "jpg" or ext == "JPG":
		c = a + i
		f = open(c, "rb")
		image = f.read()
		if image[0] == 0x89 and image[1] == 0x50:
			print(">> Will transform " + i + " in PNG, because it's a PNG file...")
			name = i[0:-4] + ".png"
			command = "mv " + a + i + " " + a + name
			os.system(command)
	else:
		print(">> " + i + " is already marks as a png file")
		
		
print("\n")
choice = input("Would you like to delete all the png files ? (yes/no) :")

c = 1

while c :
  if choice == "yes" or choice = "YES":
    b = os.listdir(a)
    for i in b:
      ext = i[len(i)-3:len(i)]
      if ext == "png" or ext == "PNG":
        print(">> Deleting " + i")
        command = "rm " + i
        os.system(command)
    print("-- Done --")
    c = 0
  elif choice == "no" or choice == "NO":
    print("-- Done --")
    c = 0
  else :
    c = 1