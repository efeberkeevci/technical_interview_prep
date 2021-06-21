
class Node{
    public:
        Node * left_node;
        Node * right_node;
        int data;

        Node(int data){
            data = data;
        }
};

class BinarySearchTree{
    public:
        Node root;

        /*
                5
            2       7
        1       3
        */
        void insertNode(int data){
            //find correct place to insert
            Node new_node(data);
            /*
            if(root == NULL){
                root = new_node;
            }
            */
            
        }

        void deleteNode(int data){

        }

        void inOrderTraversal(){}

        void preOrderTraversal(){}

        void postOrderTraversal(){}

        Node * find(int data){
            
        }

};
