#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Hello everyone"<<endl;
    
    
    string filename = "compressed.txt";
    std::ifstream inp(filename);
    std::vector<std::string> first_words;
    std::string line;




  //   while (std::getline(inp, line)) {
  //       std::istringstream iss(line);
  //       std::string word;
  //       // if (iss >> word) {
  //           string tmp;
  // /*while (std::getline(inp, tmp)) {
  //   first_words.push_back(tmp.substr(0, tmp.find_first_of(" ")));
  // }
  //   for (auto i : first_words) {
  //   std::cout << i << '\n';
  // }*/
  // cout<<line;

    std::vector<std::string> second_words;
            string tmp2;

    std::vector<std::string> second_words1;
            string tmp1;


//            // first_words.push_back(word);
//            // cout<<word;
    while (std::getline(inp, tmp2)) 
    {
      second_words.push_back(tmp2.substr(0, tmp2.find_first_of(" ")));
      
        while (std::getline(inp, tmp1)) 
        {
            second_words1.push_back(tmp1.substr(0, tmp1.find_first_of("\n")));
        }

    }



    for (auto i : second_words) {
    std::cout << i << '\n';
  }
cout<<endl<<endl;
      for (auto i : second_words1) {
    std::cout << i << '\n';
  }
//             cout<<"char: ";
//            // first_words.push_back(word);
//            // cout<<word;
//             // search(root,word,0);
//             //cout<<endl<<word<<endl;
//             /*while(getline(cin,line)){
//                 iss>>word;
//                 cout<<word<<" ";
//             }*/
//             // if(iss>>word){
//             // cout<<endl<<word<<endl;
                
//             // }
//             string output;

//             while(getline(inp , output,'\t')){
//                  inp>>output;
//                  cout<<" "<<output<<" ";
//             }
//             // iss>>word;
//             // cout<<endl<<word<<endl;
//             // iss>>word;
//             // cout<<endl<<word<<endl;
// //continue here; read in first string in each line of compressed file and traversed the tree to find the char of that line
// //need to do: read the rest of strings in to an array maybe and then while array not empty 'string[array of positions] = word'

            cout<<endl;
                return 0;

            }
            
      //  }
        
