#include <iostream>

using namespace std;

int valtab[127];
class Tree;

class Node
{
    private:
        friend class Tree;
        friend ostream& operator<<(ostream&, const Tree&);
        int use;
    protected:
        Node(){ use = 1; }
        virtual void print(ostream&) = 0;
        virtual ~Node() {}
        virtual int eval() = 0;
};

class Tree
{
    private:
        friend class Node;
        friend ostream& operator<<(ostream&, const Tree&);
        Node* p;
    public:
        Tree(int);
        Tree(char);
        Tree(char, Tree);
        Tree(char, Tree, Tree);
        Tree(const Tree& t) { p=t.p; ++p->use; }
        ~Tree() { if(--p->use == 0) delete p; }
        void operator=(const Tree& t);
        int eval() { return p->eval(); }
};

class LeafNode : public Node
{
    private:
        friend class Tree;
        void print(ostream& o) = 0;
        virtual int eval() = 0;
};

class IntNode : public LeafNode
{
    private:
        friend class Tree;
        int n;
        void print(ostream& o) { o << n; }
        IntNode(int k): n(k) {}
    public:
        int eval() { return n; }
};

class IdNode : public LeafNode
{
    private:
        friend class Tree;
        char name;
        void print(ostream& o) { o << name; }
        IdNode(char id): name(id) {}
    public:
        int eval() {return valtab[name]; }
};

class UnaryNode : public Node
{
    private:
        friend class Tree;
        char op;
        Tree opnd;
        UnaryNode(char a, Tree b): op(a), opnd(b) {}
        void print(ostream& o) { o << "(" << op << opnd << ")"; }
    public:
        int eval();
};

class BinaryNode : public Node
{
    private:
        friend class Tree;
        char     op;
        Tree left;
        Tree right;
        BinaryNode(char a, Tree b, Tree c): op(a), left(b), right(c) {}
        void print(ostream &o) { o << "(" << left << op << right << ")"; }
    public:
        int eval();
};

int UnaryNode::eval()
{
    switch (op)
    {
        case '-': return (-opnd.eval());
        case '+': return (+opnd.eval());
        default: cerr << "no operand\n" << endl;
            return 0;
    }
}

int BinaryNode::eval()
{
    switch (op)
    {
        case '-': return ( left.eval() - right.eval() );
        case '+': return ( left.eval() + right.eval() );
        case '*': return ( left.eval() * right.eval() );
        default: cerr << "no operand\n" << endl;
                return 0;
    }
}

Tree::Tree(int n)
{
    p = new IntNode(n);
}

Tree::Tree(const char id)
{
    p = new IdNode(id);
}

Tree::Tree(const char op, Tree t)
{
    p = new UnaryNode(op, t);
}

Tree::Tree(const char op, Tree left, Tree right)
{
    p = new BinaryNode(op, left, right);
}

ostream& operator<<(ostream& o, const Tree& t)
{
   t.p -> print(o);
   return (o);
}

int main()
{
    valtab['A'] = 3;
    valtab['B'] = 4;
    cout << "A = 3,  B = 4" << endl;
    Tree t1 = Tree('*', Tree('-', 5), Tree('+', 'A', 4));
    Tree t2 = Tree('+', Tree('-', 'A', 1), Tree('+', t1, 'B'));
    cout << "t1 = " << t1 << " ;  t2 = " << t2 << endl;
    cout << "t1:" << t1.eval() << "  t2:" << t2.eval() << endl;
}