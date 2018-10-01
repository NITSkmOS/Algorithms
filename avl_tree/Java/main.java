public class AVLOPERATONS {
    public static void main(String[] args) {
        AVLDeclaration root = new AVLDeclaration(56);
        AVLDeclaration left1 = new AVLDeclaration(48);
        AVLDeclaration right1 = new AVLDeclaration(59);
        AVLDeclaration left12 = new AVLDeclaration(32);
        AVLDeclaration right12 = new AVLDeclaration(50);
        AVLDeclaration right11 = new AVLDeclaration(60);
        AVLDeclaration right111 = new AVLDeclaration(62);

        root.setHeigth(1);
        root.setleft(left1);
        root.setRight(right1);
        left1.setleft(left12);
        left1.setRight(right12);
        right1.setRight(right11);
        right1.setHeigth(2);
        right11.setRight(right111);
        right11.setHeigth(2);
        right111.setHeigth(3);
        left1.setHeigth(2);
        left12.setHeigth(2);
        right12.setHeigth(3);
    }

    public  int height(AVLDeclaration root){
        if(root == null)
            return -1;
        else
            return root.getHeight();
    }


    public AVLDeclaration leftLeftRotation(AVLDeclaration x){
        AVLDeclaration w = x.getleft();
        x.setleft(w.getright());
        w.setRight(x);
        x.setHeigth(Math.max(height(x.getleft()),height(x.getright()))+1);
        w.setHeigth(Math.max(height(w.getleft()),height(x))+1);

        return w;
    }

    public AVLDeclaration rightRightRotation(AVLDeclaration x){
        AVLDeclaration w = x.getright();
        x.setRight(w.getleft());
        w.setleft(x);
        x.setHeigth(Math.max(height(x.getleft()),height(x.getright()))+1);
        w.setHeigth(Math.max(height(w.getright()),height(x))+1);

        return w;
    }

    public AVLDeclaration leftRightrotation(AVLDeclaration z){
        z.setleft(rightRightRotation(z.getleft()));
        return leftLeftRotation(z);
    }

    public AVLDeclaration rightLeftRotation(AVLDeclaration z){
        z.setRight(leftLeftRotation(z.getright()));
        return rightRightRotation(z);
    }


    public AVLDeclaration insert(AVLDeclaration root, AVLDeclaration parent, int data){
        if(root == null){
            root = new AVLDeclaration(data);
            root.setHeigth(0);
            root.setleft(null);
            root.setRight(null);
        }
        else if(data < root.getData()){
            root.setleft(insert(root.getleft(), root, data));
            if(height(root.getleft()) - height(root.getright()) == 2){
                if(data < root.getleft().getData())
                    root = leftLeftRotation(root);
                else
                    root = leftRightrotation(root);
            }
        }
        else if(data > root.getData()){
            root.setRight(insert(root.getright(), root, data));
            if(height(root.getright()) - height(root.getleft()) == 2){
                if(data < root.getright().getData())
                    root = rightRightRotation(root);
                else
                    root = rightLeftRotation(root);
            }
        }
        root.setHeigth(Math.max(height(root.getleft()), height(root.getright())) + 1);
        return root;
    }

}
