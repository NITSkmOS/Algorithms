import java.util.*;

public class BFS {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int V = s.nextInt();
		int E = s.nextInt();

		int edges[][]=new int [V][V];
        for(int i=0;i<E;i++){
            int fv=s.nextInt();
            int sv=s.nextInt();
            edges[fv][sv]=1;
            edges[sv][fv]=1;
        }
        int sv=s.nextInt();
        int ev=s.nextInt();
        boolean visited[]=new boolean[V];
        ArrayList<Integer> out=getPathBFS(edges,visited,sv,ev);
        for(int i:out)
            System.out.print(i+" ");
	}
    
    private static ArrayList<Integer> getPathBFS(int edges[][], boolean visited[],int sv,int ev){
        ArrayList<Integer> out=new ArrayList<>();
        if(sv==ev){
            out.add(sv);
            return out;
        }
        Queue<Integer> q=new LinkedList<>();
        HashMap<Integer,Integer> map=new HashMap<>();
        q.add(sv);
        visited[sv]=true;
        while(!q.isEmpty()){
            int v=q.remove();
            for(int i=0;i<edges.length;i++){
                if(edges[v][i]==1 && !visited[i]){
                    map.put(i,v);
                    q.add(i);
                    visited[i]=true;
                    if(i==ev){
                        break;
                    }
                }
            }
        }
        if(!map.containsKey(ev))
            return null;
        out.add(ev);
        while(ev!=sv){
            out.add(map.get(ev));
            ev=map.get(ev);
        }
        return out;
    }

}
