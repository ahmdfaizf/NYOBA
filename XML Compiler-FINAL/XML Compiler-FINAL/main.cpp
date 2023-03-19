#include "CompXML.h"

int main() {
    ifstream myFile;
    string Line1, Isi, buffer, strtag, namaFile;
    StackTag S;
    QueueStatus Q;
    Queue tags;
    bool Format, Pasangan;
    bool elementHasName = true;
    int rootOrder = 0, countFirstRoot = 0;

    cout << "Masukkan nama file beserta tipe data: ";
    cin >> namaFile;

    string line;
    // set<string> tagName;

    createQueue(Q);
    createStack(S);
    createQueue(tags);

    myFile.open(namaFile);

    getline(myFile, Line1);

    while (getline(myFile, buffer)) {
        olahString(buffer, tags, elementHasName, rootOrder, countFirstRoot);
        Isi.append(buffer);
    }

    Stack tagStacks;
    createStack(tagStacks);

    bool isValid = true;

    pairing(isValid, tags, tagStacks, countFirstRoot, elementHasName);

    strtag = PisahTAG(Isi);
    // cout<<strtag;
    cout<<"\nDAFTAR TAG(S)" << endl << endl;
    EnqueuTAG(Q, strtag);
    PrintQueue(Q);

    cout << endl << endl;

    Format = CekFormatTag(Q);
    Pasangan = cekPasaangan(Q);

    if(Format == true && Pasangan == true && isValid){
        cout<<"FILE XML VALID\n";
    }else{
        cout<<"FILE XML TIDAK VALID\n";
    }
    myFile.close();

    return 0;
}

