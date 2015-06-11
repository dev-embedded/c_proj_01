Thanks Dong LING, Song ZHOU & Tao SUN for your hard work! 
Since this is the beginning of a series of C Language small projects, there must be a lot of problems. We did have and suffer form those problems, we discussed, debated, argued and even disputed. But as a team, we worked together to complete this sub-project finally! 
Nothing is perfect, we gonna make progresses step by step. Thanks again for your help! 


*** REPORT of lib_string SUB-PROJECT ***

0. Project information

Project Description: to realize the string operation functions (strlen, strcat, strcmp, strcpy, strinsert, strreplace, strlocation ... ) with C languate.

Project duration: from May 03, 2015 (Project created by Tao) 
		  to   May 15, 2015 (Tao created the buffer sub-project)

Team member: 	  Dong LING, Song ZHOU, Tao SUN & Jue QU.

 
---------------------------------

1. About development environment

1.1 We work in Ubuntu 12.04, we use Eclipse as project IDE and we installed the github plugin in Eclipse to manage the coding.
We got a lot problems on how to pull/push code with github plugin, and how to merge code from different person, but we fixed the problems with team-work.

1.2 We used the master branch of github to manage the coding of team members. We will try personnal branches and the dev branch in the next sub-project. 

1.3 We don't have any project management during the development, we will try the Agile to manage the next sub-project.


---------------------------------

2. About the project architecture

Tao made the first architechure of the single string project, and then I made the architecture to contain whole of the C library & function sub-projects based on Tao's original one. Dong & Song also gave a lot of suggestion on the architecture building.

So far, for the lib_string part, we have the following agreement:
(And we will update these items later to match the other sub-projects.)

a). This is the test project based on C Language.

b). There are 3 files in this root folder: main.c; Makefile; & _README

c). Each sub-folder in this root folder is a sub-project. 
c-1) A sub-project could be a library, a small function, or anything else. c-2) There could be .c .h .a .o files created in the sub-folder for this sub-project. 
c-3) The sub-project should be packed inside the sub-folder. 
c-4) Any head file or function to test this sub-project should be put inside the sub-folder.

d). The name of the sub-folder could be like: "usage_description". i.e. The sub-folder of a sub-project of creating a string library could be: lib_string The reason why I put it in this way is that when we list the sub-folders in alphabetical order later, it would be easily to find all the libs (functions, or any other thins) together.

e). The first sub-project is lib_string, created on May 03, 2015.


---------------------------------

3 About the project outline

With the help of JianPing, Tao worked out the brief of the outline of the whole C language project which is listed as following:

a). string  // for this sub-project
b). Buffer
c). IPC (Shmmem, PIPE, MsgQueue, condition variable, mutex)
d). Socket, SOAP
e). file IO (FIFE fread/read, fopen/open ...)
f). C command: int main(int argc, char **argv)

---------------------------------

----------------------------------------------------
|The following is the report of technical details: |
----------------------------------------------------


4. About Makefile

Tao create the Makefile in the project root folder, we might need create Makefile in each sub-folder later.


---------------------------------

5. About .h file

5.1 For each .c file, there should be one .h file matches the .c file with the same file name. And there could be a .h included in the floder for defining the all the global values, & including this .h file in the other .c files.  
In sub-project lib_string, I did not follow this rule, this is informal.
We will follow this rule in the next sut-project.

5.2 For global values, if we want to put them in the following block,
#ifndef XXXX_XXX_H
#define XXXX_XXX_H
...
#endif
We have two ways to define them:
-a). Using "#define CNAME value" in one .h file, and then include this .h file in the other .c files which will use the value. (The weak point is that we can't define the value type.)
-b). Define the value in one .c file, then declare the value in a .h file with "extern type value", and then include the .h file in the other .c files which will use this value.

---------------------------------

6. About the string functions

6.1 In functions, Jue uses char array more, while Song & Tao uses char pointer more.

6.2 All the functions uploaded to github have been tested with the str_test function. 

6.3 We also find the C coding style problem, we hope we can make progress in the next sub-project.


---------------------------------

--- May 29, 2015 ---
--- Reporter: JQ ---

************ THE END ***************

 
