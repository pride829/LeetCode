/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null)
            return null;
        
        Node c_head = new Node(head.val);
        Node c_node = c_head;
        c_node.random = head.random;
        Node[] arr = new Node[1000];
        Map<Node, Integer> map = 
                        new HashMap<Node, Integer>();
        int q = 0;
        map.put(head, q);
        arr[q++] = c_node;
        
        
        while(head.next != null){
            
            c_node.next = new Node(head.next.val);
            c_node.next.random = head.next.random;
            head = head.next;
            c_node = c_node.next;
            
            map.put(head, q);
            arr[q++] = c_node;
        }
        
        for(int i = 0; i < q; i++){
            //System.out.println(map.get(arr[i].random));
            if(arr[i].random != null)
            arr[i].random = arr[map.get(arr[i].random)];
        }
        
        
        return c_head;
    }
}