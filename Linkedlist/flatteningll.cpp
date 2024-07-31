Node *mergetwo(Node *l1,Node *l2){
    Node* temp = new Node(-1);
    Node* res = temp;
    while(l1!=NULL && l2!=NULL){
        if(l1->data<=l2->data){
            res->bottom=l1;
            l1=l1->bottom;
        }
        else{
            res->bottom=l2;
            l2=l2->bottom;
        }
        res=res->bottom;
    }
    if(l1!=NULL){
        res->bottom=l1;
    }
    else{
        res->bottom=l2;
    }
    return temp->bottom;
}
Node *flatten(Node *root)
{
   Node* temp = root;
   if(temp==NULL || temp->next==NULL){
       return temp;
   }
   root->next = flatten(temp->next);
   temp = mergetwo(temp , root->next);
   return temp;
}