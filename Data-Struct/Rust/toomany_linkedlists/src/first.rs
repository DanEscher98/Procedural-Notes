use std::mem;

pub struct List {
    head: Link
}

enum Link {
    Emtpy,
    More(Box<Node>)
}

struct Node {
    elem: i32,
    next: Link
}

// :: namespace operator
// self - Value (gift)
// &mut self - Mutable reference (borrow)
// &self - Shared reference 

impl List {
    pub fn new() -> Self {
        List { head: Link::Emtpy }
    }
    pub fn push(&mut self, elem: i32) {
        let new_node = Box::new(Node {
            elem: elem,
            next: mem::replace(&mut self.head, Link::Emtpy)
        });
        self.head = Link::More(new_node);
    }
    pub fn pop(&mut self) -> Option<i32> {
        match mem::replace(&mut self.head, Link::Emtpy) {
            Link::Emtpy => None,
            Link::More(node) => {
                self.head = node.next;
                Some(node.elem)
            }
        }
    }
}

impl Drop for List {
    fn drop(&mut self) {
        let mut cur_link = mem::replace(&mut self.head, Link::Emtpy);
        while let Link::More(mut boxed_node) = cur_link {
            cur_link = mem::replace(&mut boxed_node.next, Link::Emtpy);
        }
    }
}

// The whole test module should only be compiled if
// we're running tests.
#[cfg(test)]
mod test {
    use super::List;
    #[test]
    fn basics() {
        let mut list = List::new();
        // Check empty list behaves right
        assert_eq!(list.pop(), None);
        list.push(1);
        list.push(2);
        list.push(3);
        assert_eq!(list.pop(), Some(3));
        assert_eq!(list.pop(), Some(2));

        list.push(4);
        assert_eq!(list.pop(), Some(4));
        assert_eq!(list.pop(), Some(1));
        assert_eq!(list.pop(), None);
    }
}
