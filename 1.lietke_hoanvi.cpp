// Bài toán liệt kê các hoán vị (vòng tròn) của n phần tử
#include <iostream>
#include <fstream>

using namespace std;
// --init--
#define sophantu_n 5
#define max_n 16
#define output_file "result.txt"
bool check[max_n] = {false};
int result[max_n];

long giaithua(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * giaithua(n - 1);
}
void display()
{
    for (int i = 1; i <= sophantu_n; i++)
    {
        cout << result[i] << "  ";
    }
    cout << endl;
}
fstream resultFile;

void writeFileText(string OutputFile, int n) //ghi cac hoan vi ra file text
{
    //check empty file ----> temporarily failed 
    // c1: 
    // if (resultFile.peek() == resultFile.eof())
    // {
    //     resultFile << giaithua(sophantu_n - 1) << " hoan vi\n";
    // }
    // c2: 
    // resultFile.seekg(0, resultFile.end);
    // if (resultFile.tellg() == 0)
    // {
    //     resultFile << giaithua(sophantu_n - 1) << " hoan vi\n";
    // }
    for (int i = 1; i <= n; i++)
    {
        resultFile << result[i] << "  ";
    }
    resultFile << endl;

}

void XetViTriThu(int k)
{
    for (int i = 2; i <= sophantu_n; i++)
    {
        //check if the element was chosen or not
        if (!check[i])
        {
            result[k] = i; //dat 1 phan tu vao hoan vi
            check[i] = true;
            if (k == sophantu_n)
            {
                display();
                writeFileText(output_file, sophantu_n);
            }
            else
            {
                XetViTriThu(k + 1);
            }
            check[i] = 0; //tra ve tt ban dau de dung cho hoan vi tiep theo
        }
    }
}

int main()
{
    cout << "Hoan vi vong tron cua " << sophantu_n << " phan tu la: " << sophantu_n - 1 << "! = " << giaithua(sophantu_n - 1) << endl;
    result[1] = 1; //cố định 1 phần tử
    resultFile.open(output_file, ios::app);
    resultFile << giaithua(sophantu_n - 1) << " hoan vi\n";
    XetViTriThu(2);
    resultFile.close();
    cout << "Have already successfully written file " << output_file << endl;
    return 0;
}