2026-10-17 - Snap & Style: Camera Capture + Photo Effects on the Profile Picture Step

PIC: Alexander Solis (Associate Product Manager)

## A. Hypothesis

### Problem

(What problem are you trying to solve with this experiment?)

- Internal data shows users who upload a profile picture engage on the platform significantly more — yet a large share of new users reach the end of onboarding (Step 3 of 3, "Make your profile personal") without ever uploading one.
- External corroboration that profile photos drive engagement: LinkedIn reports that members with a profile photo receive up to 2x more profile views and 3x more connection requests (LinkedIn Help). For a platform where employers reach out to students, a missing photo directly reduces the user's chance of being contacted.
- Photo upload is a known high-friction onboarding step. In Inner Circle's onboarding funnel analysis, photo upload was the single biggest drop-off point, and reducing friction there lifted registration completion from 62.5% to 70.5%.
- The current step requires a pre-saved png/jpg file (max 3mb). Our target users — students and new grads — frequently don't have a suitable headshot file on hand, especially on desktop, so they skip the step entirely.
- The step is framed as a chore ("Select a file"), not a benefit. Self-conscious users who don't like how they look in photos have no easy way to improve the shot — filters already exist in our post-upload editor (Filter/Colors/Markup tabs) but are buried where most users never find them.

### Proposed change

(Describe a change you'd like to test to solve the problem)

- Add a "Take a photo" option alongside "Upload Photo" in the *Update your profile picture* modal:
  - Mobile: native camera via `<input type="file" accept="image/*" capture="user">` (front camera default).
  - Desktop: live webcam capture via `navigator.mediaDevices.getUserMedia`.
  - "Upload Photo" remains available at all times — take-a-photo is an addition, not a replacement.
- Surface photo filters/effects at the capture/confirm step: a tray of preset effects (e.g., Original, Bright, Warm, B&W, Soft) rendered as thumbnails and applied live to the preview, so the user sees a better-looking photo before committing. These effects exist today only as post-upload editor tabs; this change brings them forward to the moment of decision.
- Keep all existing constraints and editor behavior: captured photos are saved as jpg/png within the same 3mb-equivalent size cap, and users can still open the full editor (crop/rotate/flip) after capturing.

### Result and success metrics

(What is the hypothesized result? How are you going to measure it?)

- Hypothesized result: lowering the friction of getting a photo (no file needed — just look at the camera) and reducing self-consciousness (instant effects that improve the shot) increases the percentage of users who save a profile picture during onboarding.
- Primary metric — **photo-upload completion rate**: (users who save a profile photo on Step 3) / (users who reach Step 3). Target: +15% relative lift vs. control (minimum detectable effect to be finalized with analytics).
- Secondary metrics: Step 3 completion rate (Save clicked), overall onboarding completion, upload-method mix (% camera vs. % file), filter adoption rate (% of savers who applied an effect).
- Guardrail metrics: camera-permission denial rate, Step 3 abandonment, photo-quality/moderation rejection rate, page load performance.
- Statistical setup: 95% confidence, 80% power, 50/50 random split, minimum 2-week runtime or until the pre-computed sample size is reached — no early peeking.

## B. Experiment Setup

### Location

(Where will this experiment be set up?)

- Onboarding funnel, Step 3 of 3 ("Make your profile personal"): the Upload panel ("Select a file" button) and the "Update your profile picture" modal.
- Web app on both desktop and mobile browsers.

### Audiences

(Will all visitors / users be able to view the experiment?)

- All new users who reach Step 3 during onboarding, randomized 50/50 into control vs. variant.
- Existing users who edit their profile later are excluded, keeping the measurement focused on the onboarding funnel.

### Tracking

(What are the metrics that you will measure? How do they give you insights?)

- Events to instrument: `step3_viewed`, `update_picture_modal_opened`, `upload_photo_clicked`, `take_photo_clicked`, `camera_permission_granted`, `camera_permission_denied`, `photo_captured`, `photo_retaken`, `filter_selected` (with effect name), `photo_saved`, `save_clicked`, `step3_abandoned`, `onboarding_completed`.
- Insights: a per-method funnel shows which path (camera vs. file) converts users who would otherwise skip; the permission-denial event reveals whether the camera prompt introduces new friction; correlating `filter_selected` with `photo_saved` tells us whether effects are driving the lift or if it's purely the camera option.

## C. Variations Design

### Variations

(Explain each variation, give it a unique name to be easily referenced)

- **Control — "Upload-Only" (current experience):** User clicks "Select a file" → the *Update your profile picture* modal shows a single "+ Upload Photo" button → after selecting a file, the post-upload editor opens (rotate/flip controls, angle dial, and Filter/Colors/Markup tabs) → Save → returns to the profile preview.
- **Variant 1 — "Snap & Style":** The *Update your profile picture* modal shows two equal-weight CTAs: "Upload Photo" and "Take a photo" (camera icon). Tapping "Take a photo" opens a live viewfinder (front camera by default) with a capture button and a retake option. At the confirm step, a tray of preset effect thumbnails (e.g., Original, Bright, Warm, B&W, Soft) is applied live to the captured photo — the user sees the styled result immediately and can pick one or keep the original. The user can still open the full editor for crop/rotate before saving. If camera permission is denied or no camera exists, the flow falls back gracefully to "Upload Photo" with friendly copy (e.g., "No camera access — you can upload a photo instead"). Save → same profile preview as control.

## D. Result & Learnings

Not used

## Sources referenced

- LinkedIn Help — members with a profile photo receive up to 2x more profile views and 3x more connection requests (linkedin.com/help/linkedin).
- Bakhshi et al., "Why We Filter Our Photos and How It Impacts Engagement," ICWSM 2015 — analysis of 7.6M Flickr photos: filtered photos are 21% more likely to be viewed and 45% more likely to be commented on.
- Inner Circle onboarding case study — photo upload identified as the biggest funnel drop-off; friction reduction raised registration completion from 62.5% to 70.5% (billiegray.com/projects/onboarding).
- web.dev, "Capturing an image from the user," and MDN `getUserMedia` documentation — technical feasibility of the `capture` attribute (mobile) and webcam capture (desktop).
