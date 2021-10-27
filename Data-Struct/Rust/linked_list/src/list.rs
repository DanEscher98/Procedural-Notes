#[derive(Clone)]
pub enum Address {
    // Box: this is a pointer that references
    // an object on the heap
    Address(Box<LinkedList>),
    Nil
}

#[derive(Clone)]
pub struct LinkedList {
    pub data: u32,
    pub next: Address
}

impl LinkedList {
    pub fn append(&mut self, elem: u32) {
        match self.next {
            Address::Address(ref mut next_address) => {
                next_address.append(elem);
            }
            Address::Nil => {
                let node = LinkedList {
                    data: elem,
                    next: Address::Nil
                };
                self.next = Address::Address(Box::new(node))
            }
        }
    }
    pub fn delete_value(&mut self, elem: u32) {
        match self.next {
            Address::Address(ref mut next_address) => {
                if next_address.data == elem {
                    println!("Deleting value: {}", next_address.data);
                    self.next = next_address.next.clone();
                } else {
                    next_address.delete_value(elem);
                }
            }
            Address::Nil => {
                if self.data == elem {
                    self.data = 0;
                } else {
                    println!("Value: {} does not exist", elem);
                }
            }
        }
    }
    pub fn count(&self) -> u32 {
        match self.next {
            Address::Address(ref next_address) => {
                1 + next_address.count()
            },
            Address::Nil => 0
        }
    }
    pub fn print(&self) {
        println!("{}", self.data);
        match self.next {
            Address::Address(ref next_address) => {
                next_address.print()
            }
            Address::Nil => {}
        }
    }
    pub fn update(&mut self, index: u32, elem: u32) {
        let mut i = 0;
        let mut j = self;
        if i == index {
            j.data = elem
        } while i < index {
            match j.next {
                Address::Address(ref mut next_address) => {
                    j = next_address
                }
                Address::Nil => {}
            }
            i += 1;
        }
        j.data = elem;
    }
}

