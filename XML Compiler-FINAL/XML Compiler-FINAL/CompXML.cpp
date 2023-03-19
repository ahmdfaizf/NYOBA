#include "CompXML.h"

bool IsEmpty(StackTag S){
    return S.top == -1;
}
bool IsFull(StackTag S){
    return S.top == 10000;
}
void PushStack(StackTag &S, char NewInfo){
    if(IsFull(S) == true){
        cout<<"Stack Penuh";
    }else{
        S.top++;
        S.infoTag[S.top]= NewInfo;
    }
}
void PopStack(StackTag &S, char &x){
    if(IsEmpty(S)){
        cout<<"Stack Kosong";
    }else{
        S.infoTag[S.top] = x;
        S.top--;
    }
}
void PrintStack(StackTag S){
    if (IsEmpty(S) == true){
        cout<<"Stack Kosong";
    } else {
        while(S.top != -1){
            cout<<S.infoTag[S.top];
            S.top--;
        }
    }
}
void createStack(StackTag &S) {
    S.top = 0;
}
void createQueue(QueueStatus &Q){
    Head(Q) = NULL;
    Tail(Q) = NULL;
}
adr NewQueue(string TAG){
    adr p = new ElmQueueStatus;
    info(p).TAG = TAG;
    info(p).Format = false;
    next(p) = NULL;
    return p;
}
void EnQueue(QueueStatus &Q, adr p){
    if(Head(Q) == NULL && Tail(Q) == NULL){
        Head(Q) = p;
        Tail(Q) = p;
    }else{
        next(Tail(Q)) = p;
        Tail(Q) = p;
    }
}
void DeQueue(QueueStatus &Q, adr &p){
    if(Head(Q) == NULL && Tail(Q) == NULL){
        cout<<"QUEUE KOSOSONG"<<endl;
    }else if(Head(Q) == Tail(Q)){
        p = Head(Q);
        Head(Q) = NULL;
        Tail(Q) = NULL;
    }else{
        p = Head(Q);
        Head(Q) = next(p);
        next(p) = NULL;
    }
}
void PrintQueue(QueueStatus Q){
    if(Head(Q) == NULL){
        cout<<"Queue Kosong";
    }else{
        adr p = Head(Q);
        while(p != NULL){
            cout<<"["<<info(p).TAG<<"]";
            p = next(p);
        }
    }
}

string PisahTAG(string isiFile){
    int i = 0;
    string buffer, isitag;
    bool status;
    for(i=0; i<isiFile.size(); i++){
        if(isiFile[i] == '<'){
            buffer += isiFile[i];
            status = false;
        }else if(status == false && isiFile[i] != '>'){
            if (isiFile[i] == ' ') {
                while (isiFile[i + 1] != '>') {
                    i++;
                }
            } else {
                buffer += isiFile[i];
            }
        } else if(isiFile[i] == '>'){
            buffer += isiFile[i];
            status = true;
        }
    }
    return buffer;
}
void EnqueuTAG(QueueStatus &Q, string isiFile){
    int i;
    string buffer;
    adr p;
    for(i = 0; i<isiFile.length(); i++){
        buffer += isiFile[i];
        if(isiFile[i] == '>'){
            p = NewQueue(buffer);
            EnQueue(Q, p);
            buffer.clear();
        }
    }
}
bool CekFormatTag(QueueStatus Q) {
  adr p;
  bool all_tags_formatted_correctly = true;

  while (info(Head(Q)).Format != true) {
    DeQueue(Q, p);
    string buffer = info(p).TAG;

    if (buffer[0] != '<' || buffer[buffer.size()-1] != '>') {
        info(p).Format = false;
        all_tags_formatted_correctly = false;
    } else if (buffer[2] == '>' || buffer[1] == '>'){
        info(p).Format = false;
        all_tags_formatted_correctly = false;
    } else if (buffer[1] == '/') {
        info(p).Format = true;
    } else{
        info(p).Format = true;
    }
    EnQueue(Q, p);
  }

  return all_tags_formatted_correctly;
}

bool cekPasaangan(QueueStatus Q) {
    QueueStatus open_tags;
    QueueStatus close_tags;
    QueueStatus paired_tags;
    QueueStatus unpaired_tags;
    createQueue(open_tags);
    createQueue(close_tags);
    createQueue(paired_tags);
    createQueue(unpaired_tags);

    adr p, q;
    string tag, open, close;
    int x;

    // Separate the tags into open and close tags
    while (Head(Q) != NULL) {
        DeQueue(Q, p);
        tag = info(p).TAG;
        if (tag[1] == '/') {
            EnQueue(close_tags, p);
        } else {
            EnQueue(open_tags, p);
        }
    }
    /*PrintQueue(open_tags);
    cout<<endl<<endl;
    PrintQueue(close_tags);
    cout<<endl<<endl;*/

    // Pair the tags
    while (Head(open_tags) != NULL) {
        q = Head(close_tags);
        x = info(Head(close_tags)).TAG.length();
        while(q != NULL && info(q).TAG.substr(2, x) != info(Head(open_tags)).TAG.substr(1, x)){
            q = next(q);
        }
        if(q == NULL){
            DeQueue(open_tags, p);
            EnQueue(unpaired_tags, p);
        }else{
            DeQueue(open_tags, p);
            EnQueue(paired_tags, p);
        }
    }

    if(Head(unpaired_tags) == NULL){
        return true;
    }else{
        return false;
    }
    /*PrintQueue(paired_tags);

    cout<<endl<<endl;

    PrintQueue(unpaired_tags);*/
}
void createStack (Stack &S) {
    top(S) = -1;
}
void createQueue (Queue &Q) {
    first(Q) = nullptr; last(Q) = nullptr;
}
bool emptyQueue(Queue Q) {
    return first(Q) == nullptr;
}
bool thereIsOneElement(Queue Q) {
    return next(first(Q)) == nullptr;
}
bool emptyStack(Stack S) {
    return top(S) == -1;
}
bool fullStack(Stack S) {
    return top(S) == 9999;
}
elm topStack(Stack S) {
    elm p = tagStack(S)[top(S)];
    return p;
}
void push(Stack &S, elm p) {
    if (fullStack(S)) {
        cout << "\nstack is full.\n";
    } else {
        top(S)++;
        tagStack(S)[top(S)] = p;
    }
}
void pop(Stack &S, elm &p) {
    if (emptyStack(S)) {
        cout << "\nstack is empty.\n";
    } else {
        p = tagStack(S)[top(S)];
        top(S)--;
    }
}
void enqueue(Queue &Q, elm elmnt) {
    adrs p = new elmQueue;
    info(p) = elmnt;
    next(p) = nullptr;
    if (emptyQueue(Q)) {
        first(Q) = p;
        last(Q) = p;
    } else {
        next(last(Q)) = p;
        last(Q) = p;
    }
}
void dequeue(Queue &Q, elm &elmnt) {
    if (emptyQueue(Q)) {
        cout << "\nstack is empty.\n";
    } else if (thereIsOneElement(Q)) {
        elmnt = info(first(Q));
        first(Q) = nullptr;
        last(Q) = nullptr;
    } else {
        elmnt = info(first(Q));
        first(Q) = next(first(Q));
    }
}
void olahString(string line, Queue &tags, bool &elementHasName, int &rootOrder, int &countFirstRoot) {
    bool content = false;
    //cari tag setiap baris
    for (int i = 0; i < line.length(); i++) {
        if ((line[i] == '\t' || line[i] == ' ') && !content) {
            rootOrder++;
        }
        if (line[i] == '<') {
            // Nambahin tag ke queue
            elm tag;
            name(tag) = "";
            root(tag) = rootOrder;
            i++;
            while (line[i] != '>') {
                //cek apakah dia atribut apa bukan, kalau atribut diskip
                if (line[i] == ' ') {
                    while (line[i] != '>') {
                        i++;
                    }
                } else {
                    name(tag) += line[i];
                    i++;
                }
            }
            content = true;
            if (root(tag) == 0) {
                countFirstRoot++;
            }
            if (name(tag) == "") {
                elementHasName = !elementHasName;
            }
            enqueue(tags, tag);
        }
    }
    rootOrder = 0;
}
void pairing(bool &isValid, Queue &tags, Stack &tagStacks, int countFirstRoot, bool elementHasName) {
    while (!emptyQueue(tags)) {
        // copot dari queue untuk dicek
        elm tag;
        dequeue(tags, tag);

        // kalo opening tag, masukin ke stack *karena baca dari kiri
        if (name(tag)[0] != '/') {
          push(tagStacks, tag);
        }
        // kalo closing tag, cek apakah cocok sama opening tag teratas di stack
        else {
            // pengkondisian
            if (top(tagStacks) == -1 || name(tag).substr(1) != name(topStack(tagStacks)) || root(tag) != root(topStack(tagStacks)) || countFirstRoot != 2 || !elementHasName) {
                isValid = false;
                break;
            }
            // Hapus opening tag dari stack kalo cocok

            //tagName.insert(name(tag));
            //tagName.insert(name(tagStack(tagStacks)[top(tagStacks)]));

            // cout << "<" << name(tag) << ">"/* << root(tag)*/ << " | <" << name(tagStack(tagStacks)[top(tagStacks)]) << ">"/* << root(tagStack(tagStacks)[top(tagStacks)])*/ << endl;
            pop(tagStacks, tag);
        }
    }
}





