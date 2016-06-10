#include<iostream>
#include <dirent.h>
using namespace std;

int main (int argc, char *argv[])
{
   DIR *dp;
   struct dirent *dirp;

   if (argc != 2) {
       cout<<"usage: ls directory_name"<<endl;
   }

   if ((dp = opendir(argv[1])) == NULL) {
       cout<<"can't open "<< argv[1];
   }

   while ((dirp = readdir(dp)) != NULL) {
       cout<<dirp->d_name<<endl;
   }

   closedir(dp);
   return 0;
}
