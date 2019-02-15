import random
import time
from memory_profiler import profile
from memory_profiler import memory_usage

@profile
def random_int_list(start, stop, length):
    start, stop = (int(start), int(stop)) if start <= stop else (int(stop), int(start))
    length = int(abs(length)) if length else 0
    random_list = []
    for i in range(length):
        random_list.append(random.randint(start, stop))
    return random_list

@profile
def merge_sort(array):
    def merge_arr(arr_l, arr_r):
        array = []
        while len(arr_l) and len(arr_r):
            if arr_l[0] <= arr_r[0]:
                array.append(arr_l.pop(0))
            elif arr_l[0] > arr_r[0]:
                array.append(arr_r.pop(0))
        if len(arr_l) != 0:
            array += arr_l
        elif len(arr_r) != 0:
            array += arr_r
        return array

    def recursive(array):
        if len(array) == 1:
            return array
        mid = len(array) // 2
        arr_l = recursive(array[:mid])
        arr_r = recursive(array[mid:])
        return merge_arr(arr_l, arr_r)

    return recursive(array)

@profile
def main():
    for i in range(2, 20):
            a = random_int_list(1, 100, i)
            merge_sort(a)
    
if __name__ == '__main__':
    main()	
    mem_usage = memory_usage(-1, interval=.001, timeout=.01)
    print mem_usage 

#Project description
#https://travis-ci.org/pythonprofilers/memory_profiler.svg?branch=master
#Memory Profiler
#This is a python module for monitoring memory consumption of a process as well as line-by-line analysis of memory consumption for python programs. It is a pure python module which depends on the psutil module.

#Installation
#Install via pip:

#$ pip install -U memory_profiler
#The package is also available on conda-forge.

#To install from source, download the package, extract and type:

#$ python setup.py install
#Usage
#line-by-line memory usage
#The line-by-line memory usage mode is used much in the same way of the line_profiler: first decorate the function you would like to profile with @profile and then run the script with a special script (in this case with specific arguments to the Python interpreter).

#In the following example, we create a simple function my_func that allocates lists a, b and then deletes b:

#@profile
#def my_func():
    #a = [1] * (10 ** 6)
    #b = [2] * (2 * 10 ** 7)
    #del b
    #return a

#if __name__ == '__main__':
    #my_func()
#Execute the code passing the option -m memory_profiler to the python interpreter to load the memory_profiler module and print to stdout the line-by-line analysis. If the file name was example.py, this would result in:

#$ python -m memory_profiler example.py
#Output will follow:

#Line #    Mem usage  Increment   Line Contents
#==============================================
     #3                           @profile
     #4      5.97 MB    0.00 MB   def my_func():
     #5     13.61 MB    7.64 MB       a = [1] * (10 ** 6)
     #6    166.20 MB  152.59 MB       b = [2] * (2 * 10 ** 7)
     #7     13.61 MB -152.59 MB       del b
     #8     13.61 MB    0.00 MB       return a
#The first column represents the line number of the code that has been profiled, the second column (Mem usage) the memory usage of the Python interpreter after that line has been executed. The third column (Increment) represents the difference in memory of the current line with respect to the last one. The last column (Line Contents) prints the code that has been profiled.

#Decorator
#A function decorator is also available. Use as follows:

#from memory_profiler import profile

#@profile
#def my_func():
    #a = [1] * (10 ** 6)
    #b = [2] * (2 * 10 ** 7)
    #del b
    #return a
#In this case the script can be run without specifying -m memory_profiler in the command line.

#In function decorator, you can specify the precision as an argument to the decorator function. Use as follows:

#from memory_profiler import profile

#@profile(precision=4)
#def my_func():
    #a = [1] * (10 ** 6)
    #b = [2] * (2 * 10 ** 7)
    #del b
    #return a
#If a python script with decorator @profile is called using -m memory_profiler in the command line, the precision parameter is ignored.

#Time-based memory usage
#Sometimes it is useful to have full memory usage reports as a function of time (not line-by-line) of external processes (be it Python scripts or not). In this case the executable mprof might be useful. Use it like:

#mprof run <executable>
#mprof plot
#In the case of a Python script, using the previous command does not give you any information on which function is executed at a given time. Depending on the case, it can be difficult to identify the part of the code that is causing the highest memory usage.

#Adding the profile decorator to a function and running the Python script with

#mprof run <script>
#will record timestamps when entering/leaving the profiled function. Running

#mprof plot
#afterward will plot the result, making plots (using matplotlib) similar to these:

#https://camo.githubusercontent.com/3a584c7cfbae38c9220a755aa21b5ef926c1031d/68747470733a2f2f662e636c6f75642e6769746875622e636f6d2f6173736574732f313930383631382f3836313332302f63623865376337382d663563632d313165322d386531652d3539373237623636663462322e706e67
#A discussion of these capabilities can be found here.

#Warning

#If your Python file imports the memory profiler from memory_profiler import profile these timestamps will not be recorded. Comment out the import, leave your functions decorated, and re-run.

#The available commands for mprof are:

#mprof run: running an executable, recording memory usage
#mprof plot: plotting one the recorded memory usage (by default, the last one)
#mprof list: listing all recorded memory usage files in a user-friendly way.
#mprof clean: removing all recorded memory usage files.
#mprof rm: removing specific recorded memory usage files
#Tracking forked child processes
#To create a report that combines memory usage of all the children and the parent, use the include_children flag in either the profile decorator or as a command line argument to mprof:

#mprof run --include-children <script>
#The second method tracks each child independently of the main process, serializing child rows by index to the output stream. Use the multiprocess flag and plot as follows:

#mprof run --multiprocess <script>
#mprof plot
#This will create a plot using matplotlib similar to this:

#https://cloud.githubusercontent.com/assets/745966/24075879/2e85b43a-0bfa-11e7-8dfe-654320dbd2ce.png
#You can combine both the include_children and multiprocess flags to show the total memory of the program as well as each child individually. If using the API directly, note that the return from memory_usage will include the child memory in a nested list along with the main process memory.

#Setting debugger breakpoints
#It is possible to set breakpoints depending on the amount of memory used. That is, you can specify a threshold and as soon as the program uses more memory than what is specified in the threshold it will stop execution and run into the pdb debugger. To use it, you will have to decorate the function as done in the previous section with @profile and then run your script with the option -m memory_profiler --pdb-mmem=X, where X is a number representing the memory threshold in MB. For example:

#$ python -m memory_profiler --pdb-mmem=100 my_script.py
#will run my_script.py and step into the pdb debugger as soon as the code uses more than 100 MB in the decorated function.

#API
#memory_profiler exposes a number of functions to be used in third-party code.

#memory_usage(proc=-1, interval=.1, timeout=None) returns the memory usage over a time interval. The first argument, proc represents what should be monitored. This can either be the PID of a process (not necessarily a Python program), a string containing some python code to be evaluated or a tuple (f, args, kw) containing a function and its arguments to be evaluated as f(*args, **kw). For example,

#>>> from memory_profiler import memory_usage
#>>> mem_usage = memory_usage(-1, interval=.2, timeout=1)
#>>> print(mem_usage)
    #[7.296875, 7.296875, 7.296875, 7.296875, 7.296875]
#>>> # define a simple function
#>>> def f(a, n=100):
    #...     import time
    #...     time.sleep(2)
    #...     b = [a] * n
    #...     time.sleep(1)
    #...     return b
    #...
#>>> from memory_profiler import memory_usage
#>>> memory_usage((f, (1,), {'n' : int(1e6)}))
#This will execute the code f(1, n=int(1e6)) and return the memory consumption during this execution.

#REPORTING
#The output can be redirected to a log file by passing IO stream as parameter to the decorator like @profile(stream=fp)

#>>> fp=open('memory_profiler.log','w+')
#>>> @profile(stream=fp)
#>>> def my_func():
    #...     a = [1] * (10 ** 6)
    #...     b = [2] * (2 * 10 ** 7)
    #...     del b
    #...     return a
#For details refer: examples/reporting_file.py

#Reporting via logger Module:

#Sometime it would be very convenient to use logger module specially when we need to use RotatingFileHandler.

#The output can be redirected to logger module by simply making use of LogFile of memory profiler module.

#>>> from memory_profiler import LogFile
#>>> import sys
#>>> sys.stdout = LogFile('memory_profile_log')
#Customized reporting:

#Sending everything to the log file while running the memory_profiler could be cumbersome and one can choose only entries with increments by passing True to reportIncrementFlag, where reportIncrementFlag is a parameter to LogFile class of memory profiler module.

#>>> from memory_profiler import LogFile
#>>> import sys
#>>> sys.stdout = LogFile('memory_profile_log', reportIncrementFlag=False)
#For details refer: examples/reporting_logger.py

#IPython integration
#After installing the module, if you use IPython, you can use the %mprun, %%mprun, %memit and %%memit magics.

#For IPython 0.11+, you can use the module directly as an extension, with %load_ext memory_profiler

#To activate it whenever you start IPython, edit the configuration file for your IPython profile, ~/.ipython/profile_default/ipython_config.py, to register the extension like this (If you already have other extensions, just add this one to the list):

#c.InteractiveShellApp.extensions = [
    #'memory_profiler',
#]

#It then can be used directly from IPython to obtain a line-by-line report using the %mprun or %%mprun magic command. In this case, you can skip the @profile decorator and instead use the -f parameter, like this. Note however that function my_func must be defined in a file (cannot have been defined interactively in the Python interpreter):

#In [1]: from example import my_func, my_func_2

#In [2]: %mprun -f my_func my_func()
#or in cell mode:

#In [3]: %%mprun -f my_func -f my_func_2
   #...: my_func()
   #...: my_func_2()
#Another useful magic that we define is %memit, which is analogous to %timeit. It can be used as follows:

#In [1]: %memit range(10000)
#peak memory: 21.42 MiB, increment: 0.41 MiB

#In [2]: %memit range(1000000)
#peak memory: 52.10 MiB, increment: 31.08 MiB
#or in cell mode (with setup code):

#In [3]: %%memit l=range(1000000)
   #...: len(l)
   #...:
#peak memory: 52.14 MiB, increment: 0.08 MiB
#For more details, see the docstrings of the magics.

#For IPython 0.10, you can install it by editing the IPython configuration file ~/.ipython/ipy_user_conf.py to add the following lines:

#These two lines are standard and probably already there.
#import IPython.ipapi
#ip = IPython.ipapi.get()

#These two are the important ones.
#import memory_profiler
#memory_profiler.load_ipython_extension(ip)
#Frequently Asked Questions
#Q: How accurate are the results ?
#A: This module gets the memory consumption by querying the operating system kernel about the amount of memory the current process has allocated, which might be slightly different from the amount of memory that is actually used by the Python interpreter. Also, because of how the garbage collector works in Python the result might be different between platforms and even between runs.
#Q: Does it work under windows ?
#A: Yes, thanks to the psutil module.
#Support, bugs & wish list

#http://fseoane.net/static/tux_memory_small.png
#Development
#Latest sources are available from github:

#https://github.com/pythonprofilers/memory_profiler
#Projects using memory_profiler
#Benchy

#IPython memory usage

#PySpeedIT (uses a reduced version of memory_profiler)

#pydio-sync (uses custom wrapper on top of memory_profiler)

#Authors

#Tom added windows support and speed improvements via the psutil module.

#Victor added python3 support, bugfixes and general cleanup.

#Vlad Niculae added the %mprun and %memit IPython magics.

#Thomas Kluyver added the IPython extension.

#Sagar UDAY KUMAR added Report generation feature and examples.

#Dmitriy Novozhilov and Sergei Lebedev added support for tracemalloc.

#Benjamin Bengfort added support for tracking the usage of individual child processes and plotting them.

#Muhammad Haseeb Tariq fixed issue #152, which made the whole interpreter hang on functions that launched an exception.

#Juan Luis Cano modernized the infrastructure and helped with various things.

#License
#BSD License, see file COPYING for full text.
