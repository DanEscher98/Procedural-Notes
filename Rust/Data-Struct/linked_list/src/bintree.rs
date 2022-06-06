pub struct BinaryTree<T> {
    pub head: Option<BinTreeNode<T>>
}

type ChildNode<T> = Option<Box<BinTreeNode<T>>>;

struct BinTreeNode<T> {
    left: ChildNode<T>,
    right: ChildNode<T>,
    op: Operation<T>
}

enum Operation<T> {
    Add,
    Sub,
    Mul,
    Div,
    Id(T)
}

impl BinTreeNode<i32> {
    fn new(op: Operation<i32>,
        left: BinTreeNode<i32>,
        right: BinTreeNode<i32>) -> Self {
        BinTreeNode::<i32> {
            op: op, 
            left: Some(Box::new(left)),
            right: Some(Box::new(right))
        }
    }
}

impl BinaryTree<i32> {
    pub fn new(head: BinTreeNode<i32>) -> Self {
        BinaryTree::<i32> { head: Some(head) }
    }
    pub fn collapse(node: &Box<BinTreeNode<i32>>) -> i32 {
        let mut r: Option<i32> = None;
        let mut l: Option<i32> = None;
        if let Some(left) = &node.left {
            l = Some(BinaryTree::collapse(left));
        }
        if let Some(right) = &node.right {
            r = Some(BinaryTree::collapse(right));
        }

        let r = if let Some(x) = r { x } else { 0 };
        let l = if let Some(x) = l  { x } else { 0 };

        match node.op {
            Operation::Add => { r + l }
            Operation::Sub => { r - l }
            Operation::Mul => { r * l }
            Operation::Div => { if r == 0 {
                panic!("division by zero")
            } else { r / l }}
            Operation::Id(x) => x
        }
    }
}

pub fn AddNode(left: BinTreeNode<i32>,
    right: BinTreeNode<i32>) -> BinTreeNode<i32> {
    BinTreeNode::new(Operation::Add, left, right)
}
pub fn SubNode(left: BinTreeNode<i32>,
    right: BinTreeNode<i32>) -> BinTreeNode<i32> {
    BinTreeNode::new(Operation::Sub, left, right)
}
pub fn MulNode(left: BinTreeNode<i32>,
    right: BinTreeNode<i32>) -> BinTreeNode<i32> {
    BinTreeNode::new(Operation::Mul, left, right)
}
pub fn DivNode(left: BinTreeNode<i32>,
    right: BinTreeNode<i32>) -> BinTreeNode<i32> {
    BinTreeNode::new(Operation::Div, left, right)
}
pub fn IdNode(value: i32) -> BinTreeNode<i32> {
    BinTreeNode::new(Operation::Id(value), None, None)
}
