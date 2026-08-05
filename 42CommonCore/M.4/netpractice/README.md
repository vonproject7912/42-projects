*This project has been created as part of the 42 curriculum by mosriji.*

# NetPractice

## Description
NetPractice is a networking project that teaches the fundamentals of **TCP/IP addressing**. The goal is to fix broken network diagrams — configuring IP addresses, subnet masks, and routing tables — so that all devices in the simulated network can communicate correctly. There is no coding involved; it's purely about understanding and applying networking logic across 10 progressively harder levels.

## Instructions
1. Download and extract the project files into a folder of your choice.
2. Run the training interface with:
```bash
   ./run.sh
```
   If it doesn't open automatically, launch it manually:
```bash
   python3 -m http.server 49242
```
   then open `http://localhost:49242` in your browser.
3. Enter your 42 login (`mosriji`) on the welcome page to generate your personal configuration.
4. Solve each level by editing the unshaded fields (IPs, masks, routes) until the **Check again** button confirms success.
5. Once a level is validated, click **Get my config** to export the configuration file for that level, then move to the next one.

## Submission
- 10 exported configuration files (one per level) are placed at the root of this repository.
- Only the repository content is evaluated — file names have been double-checked to match each level.

## Resources
- TCP/IP addressing
- Subnet masks & CIDR notation
- Default gateways
- Routers and switches
- Routing tables
- OSI model (network layer)

**References:**
- [Subnetting basics – YouTube](https://www.youtube.com/watch?v=5WfiTHiU4x8)
- [IP addressing – YouTube](https://www.youtube.com/watch?v=oZGZRtaGyG8)

**AI usage:** AI (Claude) was used to help clarify core networking concepts (subnetting, CIDR notation, routing tables, gateways) while studying for this project, and to help draft and format this README. All configurations submitted were solved and understood manually, without AI assistance.