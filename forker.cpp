//http://www.yolinux.com/TUTORIALS/ForkExecProcesses.html

#include <iostream>
#include <string>

// Required by for routine
#include <sys/types.h>
#include <unistd.h>
/*The fork() system call will spawn a new child process which is an identical process to the parent except that has a new system process ID. The process is copied in memory from the parent and a new process structure is assigned by the kernel. The return value of the function is which discriminates the two threads of execution. A zero is returned by the fork function in the child's process.

The environment, resource limits, umask, controlling terminal, current working directory, root directory, signal masks and other process resources are also duplicated from the parent in the forked child process.*/


#include <stdlib.h>   // Declaration for exit()

using namespace std;

int globalVariable = 2;

main()
{
   string sIdentifier;
   int    iStackVariable = 20;

   pid_t pID = fork();
   if (pID == 0)                // child
   {
      // Code only executed by child process
          
      sIdentifier = "	Child Process: ";
      globalVariable++;
      iStackVariable++;
    }
    else if (pID < 0)            // failed to fork
    {
        cout << "Failed to fork" << endl;
        exit(1);
        // Throw exception
    }
    else                                   // parent
    {
      // Code only executed by parent process

      sIdentifier = "Parent Process:";
    }

    // Code executed by both parent and child.
  
    cout << sIdentifier;
    cout << " Global variable: " << globalVariable;
    cout << " Stack variable: "  << iStackVariable << endl;
}
                
