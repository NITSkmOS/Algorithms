public class AVLDeclaration {
    private int data;
    private int height;
    private AVLDeclaration left;
    private AVLDeclaration right;

    public AVLDeclaration(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setData(int data){
        this.data = data;
    }

    public void setHeigth(int height){
        this.height = height;
    }

    public int getHeight() {
        return height;
    }

    public AVLDeclaration getleft() {
        return left;
    }

    public void setleft(AVLDeclaration left) {
        this.left = left;
    }

    public AVLDeclaration getright() {
        return right;
    }

    public void setRight(AVLDeclaration left) {
        this.right = right;
    }


    @Override
    public String toString() {
        return "AVLDeclaration{" +
                "data=" + data +
                ", height=" + height +
                ", left=" + left +
                ", right=" + right +
                '}';
    }
}