# About branches and stuff

Hi self, this is my fork(s) of QMK.

Right now I'm using two branches:

- `main_dropalt` has the firmware for my Drop Alt. It's based on the Massdrop fork of QMK, because that has some power management and failure-resilience functionality (maybe some other stuff?) for this keyboard that never got merged into upstream, and using the manufacturer's (less cool) lighting code seems to avoid the instability I got when I was using the standard "matrix rgb" lighting code. If the mfgr ever updates their fork, I can probably rebase this onto that.
    - `keyboards/massdrop/alt/keymaps/nfagerlund_md` (has suffix to avoid confusion with compiled firmwares)
    - Tags for this firmware starting from `nf_alt_v2` are built on this branch. v1 was the crashy one.
- `main_numpad` has the firmware for my ymdk np21 numpad/gamepad. It's based on upstream master. This has been rebased once or twice to pick up new commits from upstream, but the release tags (`nf_pad_vX`) remember the abandoned histories.
    - `keyboards/ymkd_np21/keymaps/nfagerlund`

I WANTED to just maintain both of these on the same branch so I could rebase and grab upstream changes more easily, but since one's based on an out-of-date fork, that's impossible. Oh well.
