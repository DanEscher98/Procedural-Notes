#[warn(dead_code)]
use list::{LinkedList, Address::Nil};
use bintree::{BinaryTree,
    AddNode, SubNode, MulNode, DivNode, IdNode};
pub mod list;
pub mod bintree;

fn main() {
    println!("Hello, world!");
    let mut head = LinkedList {
        data: 0,
        next: Nil
    };
    head.append(1);
    head.append(2);
    head.append(3);
    head.print();
    println!("List size: {}", head.count());
    head.update(2, 10);
    head.append(5);
    head.delete_value(3);
    head.print();
    // ((30 * 4) - (23 + (6 / 2)))
    let bt = BinaryTree::new(
        SubNode(
            MulNode(
                IdNode(30),
                IdNode(4)
            ),
            AddNode(
                IdNode(23),
                DivNode(
                    IdNode(6),
                    IdNode(2)
                )
            )
        )
    .
    
    println!("The result is: {}", BinaryTree::collapse
        &Box::new(bt.head.expect("No head initialized")));
}
