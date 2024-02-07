// primitive_types5.rs
//
// Destructure the `cat` tuple so that the println will work.
//
// Execute `rustlings hint primitive_types5` or use the `hint` watch subcommand
// for a hint.


fn main() {
    let cat = ("Furry McFurson", 3.5, "KING");
    let (name, age, job) = cat;

    println!("{} is {} years old and is already a {}.", name, age, job);
}
