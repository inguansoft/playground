//Library implemnts one function
//ls("pat of directory") {
//
//returns 3 lists
//        * <> All directories under this path
//        * <> List of all files on this path
//        * <int> size in bytes
//}
//
//
//(size of thos files) du (path)
//* total number of files recursively
//

#include <ls>
//2 dimention list
//TODO:
list* ls(string);

long* du(string path)
{
    long[2] results{0,0};
    long* iterative_results;
    list** directory;

    //TODO: verify inputs
    directory = ls(path); // ls: get files from current path
    //directory[0] dir strings
    //directory[1] files
    //directory[2] sizes

    // iterate and add all the file sizes
    for (long file_size : directory[2])
    {
        results[0] += file_size;
        results[1]++;
    }

    // iterate and add all the file sizes
    // iterate directories, and call du on each of them
    for (string sub_path : directory[0])
    {
        iterative_results = du(sub_path);
        results[0] += iterative_results[0];
        results[1] += iterative_results[1];
    }
    //      total += directory size
    return results;
}

