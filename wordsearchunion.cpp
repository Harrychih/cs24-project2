#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "wordsearchunion.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}


int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();
  word* vocab_head;
  vocab_head = new word;

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  string input_word1, input_word2;
  cout << "Enter word1: ";
  cin >> input_word1;
  cout << "Enter word2: ";
  cin >> input_word1;
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    word = "";
    while(true){
      fin>>word;
      if (fin.eof()) {break;}
      else{
      // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
      // Use these two strings to search/insert in your array/list of words.
        if((word == input_word1)||word == input_word2)
          add_new_word(vocab_head, word, files[i]);
      }
    }
    fin.close();
  }
  list* word_head;
  word_head = vocab_head->w_head();
  while(word_head != NULL)
  {
    cout << word_head->data_filename() << endl;
    word_head = word_head->next();
  }
  cout << "---Program exits" << endl;
  return 0;
  }



