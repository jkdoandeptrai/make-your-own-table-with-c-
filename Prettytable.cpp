#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Prettytable{
   private:
      vector<vector<string>> m_row;
      vector<string> m_head;
      vector<int> sizeCol;
      int length = 0;
      // phan chia cot:
      void findSize(){
         int size = m_head.size();
         int sizeR = m_row.size();
         for ( int r = 0; r < size; r ++){ // cot
            int max = sizeCol[r];
            for ( int i = 0; i < sizeR; i++){ // hang
               if ( m_row[i][r].length() > max ){
                  max = m_row[i][r].length();
               }
            }
            sizeCol[r] = max;
            length += max;
         }
      }
   public:
      Prettytable(vector<string> yourHeader){
         for ( auto&& i : yourHeader){
            m_head.push_back(i);
            sizeCol.push_back(i.length());
         }
      }
      void addRow(vector<string> row){
         m_row.push_back(row);
      }
      void printTable(){
         findSize();
         length = length + 6*m_head.size() + (m_head.size() - 2);
         // dau
         cout << "+";
         for ( int i = 0; i < length; i ++ ){
            cout << "-";
         }
         cout << "+";
         cout << endl;
         cout << "|";
         // header
         for (int i = 0; i < m_head.size(); i++ ){
            cout <<"  " << left <<setw(sizeCol[i] + 3) << m_head[i] << "| ";
         }
         cout << endl;
         // than
         for ( int m = 0; m < m_row.size(); m ++){
            cout << "+";
            for ( int i = 0; i < length; i ++ ){
               cout << "-";
            }
            cout << "+";
            cout << endl;
            cout << "|";
            for (int i = 0; i < m_head.size(); i++ ){
               cout <<"  " << left <<setw(sizeCol[i] + 3) << m_row[m][i] << "| ";
            }
            cout << endl;
         }
         // cuoi
         cout << "+";
         for ( int i = 0; i < length; i ++ ){
            cout << "-";
         }
         cout << "+";
         cout << endl;
         return;
      }
};
