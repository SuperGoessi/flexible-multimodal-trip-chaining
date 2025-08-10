# Flexible Multimodal Trip Chaining in a Multimodal Supernetwork

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
- **Full version**: Includes generation of a **generic multimodal supernetwork** across multiple trips and activities. For details, check out the related project: *[[link to full project](https://github.com/SuperGoessi/bi-objective-multimodal-search)]*.

---

##  Directory Structure
