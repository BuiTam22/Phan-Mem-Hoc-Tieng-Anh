#include<bits/stdc++.h>
#include <conio.h>
#include<windows.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
using namespace std;
class TuVung{
    private:
        string TiengAnh, TiengViet;
    public:
        TuVung()
        {}
        TuVung(string TiengAnh, string TiengViet)
        {
            this->TiengAnh = TiengAnh;
            this->TiengViet = TiengViet;
        }
        void nhap()
        {
            cout << "                   Nhap tu tieng Anh: "; getline(cin, this->TiengAnh);
            cout << "                   Nhap nghia tieng Viet: "; getline(cin, this->TiengViet);
        }
        void in()
        {
            int sum =1;
            while(sum<=83)
            {
                if(sum == 1)
                {
                    cout << '|';
                    sum++;
                }
                else if(sum == 4)
                {
                    cout << this->TiengAnh;
                    sum+= this->TiengAnh.size();
                }
                else if(sum == 37)
                {
                    cout << '|';
                    sum++;
                }
                else if(sum == 40)
                {
                    cout << this->TiengViet;
                    sum+= this->TiengViet.size();
                }
                else if(sum == 83)
                {
                    cout << "|\n";
                    sum++;
                }
                else 
                {
                    cout << " ";
                    sum++;
                }
            }
            cout << "                   +-----+-----------------------------------+---------------------------------------------+\n";
        }
        string getTiengAnh()
        {
            return this->TiengAnh;
        }
        string getTiengViet()
        {
            return this->TiengViet;
        }
        void setTiengAnh(string TA)
        {
            this->TiengAnh = TA;
        }
        void setTiengViet(string TV)
        {
            this->TiengViet = TV;
        }
};
int* generateUniqueRandomArray(int n) {
    int* arr = new int[n]; // Khởi tạo mảng động có n phần tử
    
    // Khởi tạo một mảng tạm chứa các giá trị từ 0 đến n-1
    int* tempArr = new int[n];
    for (int i = 0; i < n; i++) {
        tempArr[i] = i;
    }
    
    // Trộn các phần tử trong mảng tạm để tạo ra một thứ tự ngẫu nhiên
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = tempArr[i];
        tempArr[i] = tempArr[j];
        tempArr[j] = temp;
    }
    
    // Sao chép các phần tử từ mảng tạm vào mảng kết quả
    for (int i = 0; i < n; i++) {
        arr[i] = tempArr[i];
    }
    
    delete[] tempArr; // Giải phóng bộ nhớ của mảng tạm
    
    return arr;
}
int dem_dong_trong_file(string filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "                       Khong the mo file.\n";
        return 0;
    }
    int line_count = 0;
    string line;
    while (getline(file, line)) {
        line_count++;
    }
    file.close();
    return line_count;
}
vector<string> cacFilecosan()
{ 
    int value = dem_dong_trong_file("Cac_File_Da_Tao.text");
    vector<string> ans(value);
    ifstream in;
    in.open("Cac_File_Da_Tao.text");
    for(int i=0; i<value; i++)
    {
        getline(in, ans[i]);
    }
    in.close();
    return ans;
}
vector<TuVung> moFile(string tenfile)
{
    int value = dem_dong_trong_file(tenfile);
    vector<TuVung> ans(value/2);
    ifstream in;
    in.open(tenfile);
    for(int i=0; i<value/2; i++)
    {
        string tiengAnh, tiengViet;
        getline(in, tiengAnh);
        getline(in, tiengViet);
        TuVung temp(tiengAnh, tiengViet);
        ans[i] = temp;
    }
    in.close();
    return ans;
}
void taoFileMoi(string tenfile)
{
    ofstream out;
    out.open("Cac_File_Da_Tao.text", ios::app);
    out << tenfile << endl;
    out.close();
    cout << "                   Tao file thanh cong!\n";
}
void Anh_Viet(vector<TuVung> v)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "                   Nhap x neu khong muon tra loi nua :)\n\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
    int * a = generateUniqueRandomArray(v.size());
    for(int i=0; i<v.size(); i++)
    {
        cout << "                   " << i+1 << ") Tu tieng Anh: "  << v[a[i]].getTiengAnh() << endl;
        cout << "                   Nhap nghia tieng Viet: ";
        string tiengviet;
        getline(cin, tiengviet);
        if(tiengviet == v[a[i]].getTiengViet())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << endl << "                   Ban da tra loi dung!\n\n";
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        }
        else if(tiengviet == "x")
            return;
        else 
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << endl << "                   Cau tra loi dung la: " << v[a[i]].getTiengViet() << endl << endl;
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        }
    }
}
void Viet_Anh(vector<TuVung> v)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int * a = generateUniqueRandomArray(v.size());
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    system("cls");
    cout << "                   Nhap x neu khong muon tra loi nua :)\n\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
    for(int i=0; i<v.size(); i++)
    {
        cout << "                   " << i+1 << ") Tu tieng Viet: "  << v[a[i]].getTiengViet() << endl;
        cout << "                   Nhap nghia tieng Anh: ";
        string tienganh;
        getline(cin, tienganh);
        if(tienganh == v[a[i]].getTiengAnh())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << endl << "                   Ban da tra loi dung!\n\n";
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        }
        else if(tienganh == "x")
            return;
        else 
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << endl << "                   Cau tra loi dung la: " << v[a[i]].getTiengAnh() << endl << endl;
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        }
    }
}
void them_tu_vao_file(string tenfile, int n)
{
    vector<TuVung> ans;
    for(int i=1;i<=n; i++)
    {
        TuVung x;
        x.nhap();
        ans.push_back(x);
    }
    ofstream out(tenfile, ios::app);
    for(int i=0; i<ans.size(); i++)
    {
        out  <<  ans[i].getTiengAnh() << endl << ans[i].getTiengViet() << endl;
    }

}
void HienThi(vector<TuVung> v)
{
    if(v.size() == 0)
    {
        cout << endl;
        cout << "                   File rong!\n";
    }
    else
    {
        cout << "                   +-----+-----------------------------------+---------------------------------------------+\n";
        cout << "                   | STT |        Tieng anh                  |         Tieng Viet                          |\n";
        cout << "                   +-----+-----------------------------------+---------------------------------------------+\n";
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].getTiengAnh() == "" && v[i].getTiengViet() == "")
            {
                
                cout << "                   File rong!\n";
                break;
            }   
                
            else 
            {
                if(i<9)
                {
                    cout << "                   |  " << i+1 << "  ";
                }
                else if(i>=9 && i<99)
                {
                    cout << "                   | " << i+1 << "  ";
                }
                else if(i>=99 && i<999)
                {
                    cout << "                   |" << i+1 << "  ";
                }
                v[i].in();
                // if(i<9)
                //     cout <<  "                   " << i+1 << ") " << v[i].getTiengAnh() << ": " << v[i].getTiengViet() << endl << endl;
                // else if(i>=9 && i<99)
                //     cout <<  "                  " << i+1 << ") " << v[i].getTiengAnh() << ": " << v[i].getTiengViet() << endl << endl;
                // else if(i>=99 && i<999)
                //     cout <<  "                 " << i+1 << ") " << v[i].getTiengAnh() << ": " << v[i].getTiengViet() << endl << endl;
            }
             
        }
    }
}
void XoaTuVung(vector<TuVung> &v, string tenfile)
{
    HienThi(v);
    if(v.size() != 0)
    {
        lap1:
        cout << "                   Nhap so thu tu cua tu muon xoa (nhap 0 neu khong muon xoa): ";
        int n; cin >> n;
        cin.ignore();
        if(n <= v.size() && n>=1)
        {
            v.erase(v.begin() + (n-1));
            cout << "                   Xoa thanh cong!\n";
            ofstream out(tenfile);
            if(v.size() == 0)
                out << "";
            else
                for(int i=0; i<v.size(); i++)
                out << v[i].getTiengAnh() << endl << v[i].getTiengViet() << endl;
        }
        else if( n == 0)
            return;
        else 
        {
            cout << "                   So thu tu ban nhap khong hop le, vui long nhap lai!\n";
            goto lap1;
        }
    }
    else 
        return;
}
void ChinhSuaTuVung(vector<TuVung> &v, string tenfile)
{
    HienThi(v);
    if(v.size() != 0)
    {
        lap1:
        cout << "                   Nhap so thu tu cua tu muon chinh sua (nhap 0 neu khong muon chinh sua): ";
        int n; cin >> n;
        cin.ignore();
        if(n == 0)
            return;
        else if(n > v.size())
        {
            cout << "                   So thu tu ban nhap khong hop le, vui long nhap lai!\n";
            goto lap1;
        }
        v[n-1].nhap();
        cout << "                   Chinh sua thanh cong!\n";
        ofstream out(tenfile);
        for(int i=0; i<v.size(); i++)
        out << v[i].getTiengAnh() << endl << v[i].getTiengViet() << endl;
    }
    else 
        return;
}
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<TuVung> v;
    vector<string> luuFilecosan;
    bool check = true;
    while(check)
    {
        lap:
        system("cls");
         SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        cout << "                   ====================MENU====================\n";
        cout << "                   || 1. Mo file co san                      ||\n";
        cout << "                   || 2. Tao file moi                        ||\n";
        cout << "                   || 3. Thoat                               ||\n";
        cout << "                   ============================================\n";
        cout << endl;
        int luachon; 
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        cout << "                   Nhap lua chon: "; cin >> luachon;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
        cin.ignore();
        if(luachon ==  1)
        {   
            if(dem_dong_trong_file("Cac_File_Da_tao.text") == 0)
            {
                cout << "                   Chua co file nao duoc tao trong thu muc!\n";
            }
            else
            { 
                luuFilecosan = cacFilecosan();
                cout << "                   Cac file co trong thu muc la: \n";
                for(int i=0; i<luuFilecosan.size(); i++)
                {
                    cout <<  "                      " <<  i+1  << ") "<< luuFilecosan[i] << endl;
                }
                lapluachon1:
                int luachon1;
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                cout << "                   Nhap File muon chon (nhap 0 neu khong muon chon): ";
                cin >> luachon1;
                cin.ignore();
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
                if( luachon1 >luuFilecosan.size())
                {
                    cout << "                   Lua chon khong hop le!\n";
                    goto lapluachon1;
                }
                else if(luachon1 == 0)
                {
                    goto lap;
                }
                else
                    v = moFile(luuFilecosan[luachon1-1]);
                string tenfile = luuFilecosan[luachon1-1];
                
                bool test = true;
                while(test)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
                    cout << endl;
                    cout << "                   ------------------LUA CHON------------------\n";
                    cout << "                   | 1. Hien thi toan bo tu vung trong file   |\n";
                    cout << "                   | 2. Nhin tieng Viet doan tieng Anh        |\n";
                    cout << "                   | 3. Nhin tieng Anh doan tieng Viet        |\n";
                    cout << "                   | 4. Them tu vung vao file                 |\n";
                    cout << "                   | 5. Xoa tu vung trong file                |\n";
                    cout << "                   | 6. Chinh sua tu vung trong file          |\n";
                    cout << "                   | 7. Xoa File                              |\n";
                    cout << "                   | 8. Thoat                                 |\n";
                    cout << "                   --------------------------------------------\n";
                    cout << endl;
                    string luachon2;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    cout << "                   Nhap lua chon: "; getline(cin, luachon2);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
                    cout << endl;
                    if(luachon2 == "1")
                    {
                        HienThi(v);
                    }
                    else if(luachon2 == "2")
                    {
                        if(v.size() == 0)
                        {
                            cout << "                   File rong!\n";
                        }
                        else 
                             Viet_Anh(v);
                    }
                    else if(luachon2 == "3")
                    {
                        if(v.size() == 0)
                        {
                            cout << "                   File rong!\n";
                        }
                        else        
                             Anh_Viet(v);
                    }
                    else if(luachon2 == "5")
                    {
                        XoaTuVung(v, tenfile);
                    }
                    else if(luachon2 == "6")
                    {
                        ChinhSuaTuVung(v, tenfile);
                    }
                    else if(luachon2 == "7")
                    {
                        string ans = tenfile;
                        const char *filename = tenfile.c_str();
                        string qs;
                        cout << "                   Ban co chac muon xoa file khong (y/n): ";
                        getline(cin, qs);
                        if(qs == "y" || qs =="Y")
                        {
                            if (remove(filename) == 0) {
                                printf("                    File %s has been deleted.", filename);
                            } 
                            else {
                                printf("                    Error deleting file %s", filename);
                            }
                            for(int i=0; i<luuFilecosan.size();i++)
                            {
                                if(luuFilecosan[i].find(tenfile) != string::npos)
                                {
                                    luuFilecosan.erase(luuFilecosan.begin() + i);
                                }
                            }
                            ofstream out("Cac_File_Da_Tao.text");
                            for(int i=0; i<luuFilecosan.size(); i++)
                            {
                                out << luuFilecosan[i] << endl;
                            }
                            luuFilecosan = cacFilecosan();
                            test = false;
                        }
                        else 
                            test = false;
                    }
                    else if(luachon2 == "8")
                    {
                         test = false;
                         goto lap;
                    }   
                    else if(luachon2 == "4")
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        cout << "                   Nhap so tu muon them: ";
                        int n; cin >> n;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Đặt lại màu trắng
                        cin.ignore();
                        them_tu_vao_file(tenfile, n);
                        test = false;
                    }
                    cout << endl << "                                        Nhan phim bat ky de tiep tuc... ";
                    getch();
                    system("cls");
                }
            }
        }
        else if(luachon == 2)
        {
            cout << endl;
            cout << "                   Ten file phai de duoi dang .text" << endl;
            cout << "                   Nhap ten file muon tao (nhap 'x' neu ban khong muon tao file nua) : ";
            string tenfile;
            getline(cin, tenfile);
            if(tenfile != "x")
            {
                ofstream out(tenfile);
                taoFileMoi(tenfile);
            }
            else
                cout << "                   Khong tao file nao!\n";
            
            
        }
        else if(luachon == 3)
        {
            cout << "                   Ket thuc chuong trinh!";
            return 0;
        }
        else 
        {
            cout << "                   Lua chon khong hop le!\n";
        }
        cout << endl << "                                        Nhan phim bat ky de tiep tuc... ";
        getch();
        system("cls");
    }
    return 0;
}