use std::ops::Add;

#[derive(Clone, Copy, Debug, PartialEq)]
struct Point<T> {
    x: T,
    y: T,
}

impl<T: Add<Output = T>> Add for Point<T> {
    type Output = Self;
    fn add(self, other: Self) -> Self::Output {
        Self {
            x: self.x + other.x,
            y: self.y + other.y,
        }
    }
}

fn main() {
    let a = Point::<i32> { x: 2, y: 3 };
    let b = Point::<i32> { x: 4, y: 1 };
    println!("{:?}", a + b);
}
