# Project3_Randomization

Steps to build
prolog: though this step isn't strictly necessary to actually build the project it helps to make sure the user is in the right directory and all necessary configuration files have been downloaded correctly
  in the bash terminal navigate to the directory of the cloded repository. For isntance home/CS4380.
  in this root directory for the repo there should be a CMakePresets.json document.
  verify its contents are correct by running the following command
  
    cmake --list-presets=all

  after running this command you should see a dialog saying that the available configure presets are
  
    on windows:
      "windows-x64-debug" and "windows-x64-release"

    on linux:
      "linux-x64-debug" and "linux-x64-release"

Step 1:
  This is where the actual necessary steps to build and run begin

  while in the root directory of the repositories clone (such as home/CS3310-Project2_MergeSortInversionCount) run the following command to set the cmake build configuration
    
      on windows
        cmake --preset windows-x64-release (or debug for debug build)

      on linux
        cmake --preset linux-x64-release (or debug for debug build)

  Cmake will configure for the build now. The last line of the dialog will tell you what directory the build cache files have been made in.
      
      It will be ${root}/build/Release (or Debug) (CS3310-Project2_MergeSortInversionCount/build/Release)

 Step 2:
   now run the following command
   
     cmake --build ./build/Release (or Debug if debug build was specified previously)

   you will see a build process proceed
   upon completion navigate to the build/Release (or Debug) directory with the following command

     cd build/Release (or Debug)

 Step 3:
   the built executables can now be run

   To run the QuickSort program
    
      on windows
        .\QuickSort.exe <optional file-path> <optional itteration count> (file-path is to a file with new line deliminated list of integers, such as the provided FewNum.txt or LotsOfNum.txt - .\QuickSort.exe ../../LotsOfNum.txt)

      on linux
        ./QuickSort <optional file-path> <optional itteration count> (same as on windows for file-path option)

   To run the RSelect program
    
      on windows
        .\RSelect.exe <optional file-path> <optional target rank> <optional itteration count> (file-path is to a file with new line deliminated list of integers, such as the provided FewNum.txt or LotsOfNum.txt - ./QuickSort.exe ../../LotsOfNum.txt)

      on linux
        ./RSelect <optional file-path> <optional target rank> <optional itteration count> (same as on windows for file-path option)

  Upon completion the program will report how long the executed method took in execution as well as the number of comparisons counted for the given method of pivot selection

  ** When the program is not supplied with a file to read from it will generate an array of random integers (pre configured in the Project2_InversionsCountConstDeff.h file - ARRAY_SIZE variable - to 100,000) and operate on that
