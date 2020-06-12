import sys
import subprocess as sp

__author__ = "pseudo"

def main():

	depends = {}
	loadFile(depends)

	args = list(sys.argv)[1:]
	if args != []:

		# Eval cmd args
		cmd, args = args[0], args[1:]
		execCommand(cmd, args, depends)
		saveFile(depends) # Potential change
		return

	while True:

		# Catch whitespace and quit
		inp = input("~ ")
		if inp in ("q", "quit"):
			print("Goodbye!")
			break
		elif not inp or inp.isspace():
			continue

		# Break up cmd and arguments
		args = inp.split()
		cmd, args = args[0], args[1:]
		execCommand(cmd, args, depends)

	print("Saving any changes...")
	saveFile(depends)

def loadFile(depends:dict):

	# Attempt tor read from the file
	try:
		with open('pybuild.depends', 'r') as f:

			# Read from file	
			content = f.read().split("\n")

			# Iter over file lines
			for line in content:
				
				if line.isspace():
					continue # skip blank/empty lines

				# parse content
				key, args = line.split("=")
				args = args.split(",") if args else []
				
				depends[key] = args

	# File read error
	except:
		# Return an empty dict and save will create file
		return {}

def saveFile(depends:dict):

	with open("pybuild.depends", "w") as f:

		# Iter over key-val pairs
		for key, vals in depends.items():

			# Write line to the file
			f.write(f"{key}={','.join(vals)}\n")



def execCommand(cmd, args, depends):

	if cmd == "help":

		print("- - - = = = [ Help ] = = = - - -")
		print("listf ~")
		print("    [*] listf")
		print("    Will show all files that are currently registered with the program")
		print("listreqs ~")
		print("    [*] listreqs")
		print("    [*] listreqs <file>")
		print("    Will show the requirements of all or a given file")
		print("addf ~")
		print("    [*] addf <file>")
		print("    Will add a new file to the program")
		print("addreq ~")
		print("    [*] addreq <file1> <file2>")
		print("    Will declare that file1 requires file2")
		print("buildf ~")
		print("    [*] buildf <file>")
		print("    Will build a given file with all of its required dependencies")

	elif cmd == "listf":

		# List all registered files
		files = list(depends.keys())
		if files == []:
			print("There are no registered files!")
		else:
			# Show list of files
			print("Registered Files:")
			print(", ".join(files))

	elif cmd == "listreqs":

		# Handle a defined file
		if len(args) == 1:
			if args[0] not in depends.keys():
				print("File is not registered!")
			else:
				reqs = depends[args[0]]
				print(f"{args[0]} -> {', '.join(reqs) if reqs else '[]'}")
			return

		# Catch unreq args
		if len(args) != 0:
			print("Invalid Arguments!")
			print("Please use `help` if you're unsure!")
			return

		# Catch no registered files
		if depends == {}:
			print("There are no registered files!")
			return

		print("All current dependencies are:")
		for key, val in depends.items():
			print(f"{key} -> {', '.join(val) if val else '[]'}")

	elif cmd == "addf":

		# addf command will add a new file to the proj
		if len(args) != 1:
			print("Invalid Arguments!")
			print("Please use `help` if you're unsure!")
		elif args[0] in depends.keys():
			print("This file has already been registered!")
		else:
			# This file has no depencies so far
			depends[args[0]] = []

	elif cmd == "addreq":

		if len(args) != 2:
			print("Invalid Arguments!")
			print("Please use `help` if you're unsure!")
		elif args[0] not in depends.keys() or args[1] not in depends.keys():
			print("One or both of the files are not registered!")
		else:
			depends[args[0]].append(args[1])

	elif cmd == "buildf":

		if len(args) != 1:
			print("Invalid Arguments!")
			print("Please use `help` if you're unsure!")
		elif args[0] not in depends.keys():
			print("That file has not been registered yet!")
		else:

			# A file needs itself to be compiled - duh
			depsList = set([args[0]])

			toCheck = depends[args[0]][:]
			while toCheck != []:

				cur = toCheck[0]

				if cur not in depsList:
					depsList.add(cur)

					# Include chained-depends
					toCheck.extend(depends[cur])

				# shrink queue
				toCheck = toCheck[1:]

			print("Building...")
			sp.run(["gcc", "-o", f"build/{args[0].split('/')[-1][:-2]}.exe"] + list(depsList))

if __name__ == "__main__":
	main()