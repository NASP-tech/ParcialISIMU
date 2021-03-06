
template <typename type>

class DSSL: public DS<type>{
    private:
        
        NodeSL<type>* L;

        void* createNode() override {
            return malloc( sizeof( NodeSL<type> ) );
        }

    public:
        Node<type>* getRoot(){
            return L;
        }
        category getCategory() override {
            return SINGLE_LINKED_LIST;
        }

        void create() override {
            L = NULL;
        }

        int extension() override {
            int cont = 0;
            NodeSL<type>* Lcopy = L;

            while(Lcopy != NULL){
                cont++;

                Lcopy = Lcopy->next;
            }

            return cont;
        }

        void insert(type value) override {
            NodeSL<type>* temp = (NodeSL<type>*) createNode();
            temp->data = value;

            if(L == NULL)
                temp->next = NULL;
            else
                temp->next = L;

            L = temp;
        }

        void insert(int pos, type value) override {
            NodeSL<type>* temp = (NodeSL<type>*) createNode();
            temp->data = value;

            NodeSL<type>* Lcopy = L;

            for(int i = 0; i < pos-1; i++) Lcopy = Lcopy->next;

            temp->next = Lcopy->next;
            Lcopy->next = temp;
        }
        
        type extract(int pos) override {
            NodeSL<type>* Lcopy = L;

            for(int i = 0; i < pos; i++) Lcopy = Lcopy->next;

            return Lcopy->data;
        }

        void destroy() override {
            NodeSL<type>* temp;

            while(L != NULL){
                temp = L;

                L = L->next;

                free(temp);
            }
        }

        bool search(type value) override {
            bool ans = false;

            NodeSL<type>* Lcopy = L;

            while(Lcopy != NULL){
                if(Lcopy->data == value){
                    ans = true;
                    break;
                }
                Lcopy = Lcopy->next;
            }
            return ans;
        }
        int count(type value) override {
            int cont = 0;
            NodeSL<type>* Lcopy = L;

            while(Lcopy != NULL){
                if(Lcopy->data == value) cont++;

                Lcopy = Lcopy->next;
            }
            return cont;
        }

        
        void reverse() override {
            NodeSL<type>* new_one = NULL;
            NodeSL<type>* Lcopy = L;

            NodeSL<type>* temp;

            while(Lcopy != NULL){
                temp = (NodeSL<type>*) createNode();
                temp->data = Lcopy->data;
                if(new_one == NULL)
                    temp->next = NULL;
                else
                    temp->next = new_one;
                
                new_one = temp;

                Lcopy = Lcopy->next;
            }

            destroy();

            L = new_one;
        }

        void show(bool verbose) override {
            if(L == NULL){
                cout << "La lista est?? vac??a.\n";
                return;
            }
            NodeSL<type>* Lcopy = L;

            if(verbose){
                int index = 1;

                while(Lcopy != NULL){
                    cout << "Element #" << index << " is: " << Lcopy->data << "\n";
                    index++;

                    Lcopy = Lcopy->next;
                }       
            }else{
                while(Lcopy != NULL){
                    cout << Lcopy->data << " -> ";

                    Lcopy = Lcopy->next;
                }
                cout << "NULL\n";
            }
        }
};