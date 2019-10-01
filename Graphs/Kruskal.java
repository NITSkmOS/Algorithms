import java.util.Scanner;

public class Kruskal {
    
    static class Edge implements Comparable<Edge>{
        int source,dest,weight;
        public int compareTo(Edge o) {
        	return this.weight-o.weight;	//increasing order
        }
    }

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int V = s.nextInt();
		int E = s.nextInt();

		Edge[] input=new Edge[E];
        for(int i=0;i<E;i++){
            input[i]=new Edge();
            input[i].source=s.nextInt();
            input[i].dest=s.nextInt();
            input[i].weight=s.nextInt();
        }
        kruskal(input,V);
        s.close();
	}
	
	public static void kruskal(Edge input[],int n) {
//		Arrays.sort(input);
		Edge out[]=new Edge[n-1];
		int parent[]=new int[n];
		for(int i=0;i<n;i++)
			parent[i]=i;
		int i=0,c=0;
		while(c != n-1) {
			Edge curr=input[i];
			int sp=findParent(curr.source,parent);
			int dp=findParent(curr.dest,parent);
			if(sp!=dp) {
				out[c++]=curr;
				parent[sp]=dp;
			}
			i++;
		}
		for(Edge j:out) {
			if(j.source<j.dest)
				System.out.println(j.source+" "+j.dest+" "+j.weight);
			else
				System.out.println(j.dest+" "+j.source+" "+j.weight);
		}
	}
	
	public static int findParent(int v,int []parent) {
		if(parent[v]==v)
			return v;
		return findParent(parent[v],parent);
	}
    
    
}