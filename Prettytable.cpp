#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Prettytable{
   private:
      // store header:
      vector<string> m_head;
      // store values in table:
      vector<vector<string>> m_row;
      // store the max length of each row, each column. Used when print out the table.
      vector<int> sizeCol;
      // how long my table is ?
      int length = 0;
      // find the lenght:
      inline void findSize(){
         int size = sizeCol.size();
         for ( int r = 0; r < size; r ++){ // cot
            length += sizeCol[r];
         }
         length = length + 6*m_head.size() + (m_head.size() - 2);
      }
      // print some line, decorate the table.
      inline void line(int notEnd = 0){
         cout << "+";
         for ( int i = 0; i < length; i ++ ){
               cout << "-";
         }
         cout << "+";
         cout << endl;
         // if it is the end of table, I dont need the "|""
         if (!notEnd)
            cout << "|";
         return;
      }
   public:
      Prettytable(vector<string> yourHeader){
         // init your head of your table:
         for ( auto&& i : yourHeader){
            m_head.push_back(i);
            sizeCol.push_back(i.length());
         }
      }
      // remember: row.size() == m_head.size(), if not, your table will not be printed out.
      void addRow(vector<string> row){
         m_row.push_back(row);
         int size = row.size();
         for ( int i = 0; i < size; i++){ 
            int newSize = row[i].length();
            if ( newSize > sizeCol[i] ){
               sizeCol[i] = newSize; 
            }
         }
      }
      inline void printTable(){
         findSize();
         line();
         // print the head
         for (int i = 0; i < m_head.size(); i++ ){
            cout <<"  " << left <<setw(sizeCol[i] + 3) << m_head[i] << "| ";
            // I need align 6 spaces each column, |<3> value <3>|. Just make it centered
         }
         cout << endl;
         // print value:
         for ( int m = 0; m < m_row.size(); m ++){
            line();
            for (int i = 0; i < m_head.size(); i++ ){
               cout <<"  " << left <<setw(sizeCol[i] + 3) << m_row[m][i] << "| ";
            }
            cout << endl;
         }
         line(1);
         cout << endl;
         return;
      }
      // done.
};
