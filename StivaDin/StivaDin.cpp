#include <iostream>
typedef struct stiva {
    int v;
    stiva* next;
};

stiva* push(stiva* vf, int a) {
    stiva* tmp;
    tmp = (stiva*)malloc(sizeof(stiva));
    tmp->v = a;
    tmp->next = vf;
    return tmp;

}

stiva* pop(stiva* vf, int &a) {
    stiva* tmp;
    tmp = vf;
    a = tmp->v;
    if (vf->next) { 
        vf = vf->next; 
        free(tmp);
    }
    else
    {
        free(vf);
        vf = nullptr;
    }
    
    return vf;
}


int peek(stiva* vf) {
    stiva* t;
    t = vf;
    if (t) return t->v;
}

void arata(stiva* vf) {
    stiva* t;
    t = vf;

    while (t) {
        std::cout << t->v << " ";
        t = t->next;
    };

}

int main()
{
    stiva* vf, * tmp;
    int a=0;
    vf = (stiva*)malloc(sizeof(stiva));
    vf->v = 1;
    vf->next = nullptr;
    for (int i = 2; i <= 10; i++) {
        vf=push(vf, i);
    }
    arata(vf);
    std::cout << "\nPeek:" << peek(vf) <<"\n";

    std::cout << "\nPop:\n";
    while (vf) {
        vf = pop(vf, a);
        std::cout << a << " ";
        
   }

}