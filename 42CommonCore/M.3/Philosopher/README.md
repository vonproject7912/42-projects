*This project has been created as part of the 42 curriculum by <mosriji>.*

# Philosopher

# Description

**Philosopher** is a threading introduction project to learn how to avoid deadlocks or overwriting data.

The objective of this project is to:
- Understand how threads work and how to create them with `pthread`
- Learn how to use mutexes to protect shared data
- Implement the classic Dining Philosophers problem
- Detect death conditions and stop the simulation cleanly

---

# Features
None (nothing out of the ordinary mouhaha)

# Instructions

**Compilation:**
```
make
```

**Execution:**
```
./philosopher number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:
```
./philosopher 5 800 200 200
./philosopher 5 800 200 200 7
```

---

# Resources
- [Oceano Medium page of ressources](https://medium.com/@jalal92/the-dining-philosophers-7157cc05315)
- [CodeVault's amazing classes on threads](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [Oceano introduction classes to understand the probelem](https://www.youtube.com/playlist?list=PLc4DnsRQbs6b8vR0Y5p_bWNy7icCSWsHu)

---

**AI Usage:**
Claude (Anthropic) was used during this project for:

- Guidance on struct design and what fields were needed
- Understanding mutex usage and when to lock/unlock
- Debugging race conditions and timing issues
- Reviewing and correcting code logic throughout the project