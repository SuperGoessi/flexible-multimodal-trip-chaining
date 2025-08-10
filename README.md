# Flexible Multimodal Trip Chaining

**Brief Overview**  
This repository implements a simulation of **individual-level multimodal travel** and **activity participation**, integrating **private vehicle** and **public transit** modes.

---

##  Motivation & Concept

Our approach is based on the **supernetwork** concept—an integrated network made of multiple interconnected modal sub-networks.  
- When an individual **switches transport modes**, the simulation transitions from the previous mode’s network to the new mode via a **transfer link**.  
- When an individual **participates in an activity**, the simulation transitions from the pre-activity network to the post-activity network via an **activity link**.

This demo focuses on **multimodal travel with a single activity participation**, using a **trip-sequence-based logic**.

---

##  Demo vs. Full Project

- **Demo**: Demonstrates the core logic using a single activity in a trip sequence.
- **Paper**: For more theoretical details, check out the paper: *[[link to open-access paper](https://www.sciencedirect.com/science/article/pii/S2772424721000160?via%3Dihub)]
- **Full version**: Includes generation of a **generic multimodal supernetwork** across multiple trips and activities. For details, check out the related project: *[[link to full project](https://github.com/SuperGoessi/bi-objective-multimodal-search)]*.

---

## 🚀 Getting Started

This project is **C++17** only — no extra installation needed.  
You just need a working C++ compiler.
This code can be compiled directly in Visual Studio (Windows) or using `g++` / `clang++` on Linux/macOS.

## 🖼 Example Output
Below is a processed example output generated from the raw text file produced by running the demo:

<img width="522" height="473" alt="image" src="https://github.com/user-attachments/assets/7ac1749d-cd87-4f03-9b4c-a26de1f3d70a" />

**Normalized accessibility in Eindhoven city**
## 📚 Citation
If you use this code or methodology in your work, please cite:

```bibtex
@article{qin2021stp,
  title       = {Space-time prism in multimodal supernetwork – Part 1: Methodology},
  author      = {Qin, Jing and Liao, Feixiong},
  journal     = {Communications in Transportation Research},
  volume      = {1},
  pages       = {100016},
  year        = {2021},
  doi         = {10.1016/j.commtr.2021.100016},
}
```
Qin, J., & Liao, F. (2021). Space-time prism in multimodal supernetwork – Part 1: Methodology. Communications in Transportation Research, 1, Article 100016. https://doi.org/10.1016/j.commtr.2021.100016

## 🤝 Contributing
Contributions are welcome!  
If you find bugs, have feature requests, or would like to improve the code/documentation, please open an issue or submit a pull request.


