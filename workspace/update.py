#!/usr/bin/env python3
import shutil
import os
import subprocess
from datetime import date




def saveSolution(fileName):

    sourceFile = "solution.cpp"
    destinationFolder = "solution/"
    destinationFile = os.path.join(destinationFolder, fileName)

    executeCopy(sourceFile,destinationFile)


def restoreTemplate():
    templateFolder = 'workspace/'
    templateFileName = "template.cpp"
    templateFile = os.path.join(templateFolder,templateFileName)
    solutionfile = 'solution.cpp'

    executeCopy(templateFile,solutionfile)


def updateFiles(solutionFileName):
    saveSolution(solutionFileName)
    restoreTemplate()

def executeCopy(sourceFile, destinationFile):
    try:
        print(shutil.copy2(sourceFile,destinationFile))
    except:
        print("failed")





def executeGit(problem,date):

    commitMessage = "\"" + date + " " + " ".join(problem) + "\""
    print(commitMessage)

    subprocess.run(["git", "add" ,"."], check=True) 
    subprocess.run(["git", "commit","-m", commitMessage], check=True) 
    subprocess.run(["git", "push"], check=True) 


def getFile():
    with open("solution.cpp","r") as file:
        content = file.readlines()
    
    return content

def uploadFile(content):
    with open('solution.cpp','w') as file:
        file.writelines(content)

def getProblemInfo(header):
    x = header.strip().split(":")
    question = x[1].replace(".","").strip().split(" ")
    problem = [y.capitalize() for y in question]
    return problem

def editFile(content, problem,date):
    
    content[1] = '// Title: ' + " ".join(problem[1:]) + "\n"
    content[0] = "// LC: " + " ".join(problem) + "\n"
    content[3] = "// Date: " + date + '\n'

    return content



if __name__ == '__main__':
    today = date.today().strftime("%d %B %Y")
    # get file 
    content = getFile()
    # get problem number and name
    problem = getProblemInfo(content[0])
    # edit file
    content = editFile(content,problem,today)
    # update file
    uploadFile(content)
    # save solution
    updateFiles("_".join(problem) + ".cpp")
    # execute git
    executeGit(problem, today)
    