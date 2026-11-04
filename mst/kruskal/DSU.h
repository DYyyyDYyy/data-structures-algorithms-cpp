#ifndef DSU_H
#define DSU_H


class DSU {
private:
    int* previous;
    int* rank;
    int size;

public:

    DSU(int n);
    

    ~DSU();
    

    void set_make(int v);
    

    int set_find(int v);
    

    bool set_union(int v1, int v2);
    

    void initialize(int n);
};

#endif
