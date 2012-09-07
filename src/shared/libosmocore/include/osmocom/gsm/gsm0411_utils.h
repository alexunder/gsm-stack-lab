#ifndef _GSM0411_UTILS_H
#define _GSM0411_UTILS_H

struct msgb *gsm411_msgb_alloc(void);

/* Generate 03.40 TP-SCTS */
void gsm340_gen_scts(uint8_t *scts, time_t time);

/* Decode 03.40 TP-SCTS (into utc/gmt timestamp) */
time_t gsm340_scts(uint8_t *scts);

/* decode validity period. return minutes */
unsigned long gsm340_validity_period(uint8_t sms_vpf, uint8_t *sms_vp);

/* determine coding alphabet dependent on GSM 03.38 Section 4 DCS */
enum sms_alphabet gsm338_get_sms_alphabet(uint8_t dcs);

/* generate a TPDU address field compliant with 03.40 sec. 9.1.2.5 */
int gsm340_gen_oa(uint8_t *oa, unsigned int oa_len, uint8_t type,
	uint8_t plan, const char *number);

/* Prefix msg with a RP header */
int gsm411_push_rp_header(struct msgb *msg, uint8_t rp_msg_type,
	uint8_t rp_msg_ref);

/* Prefix msg with a 04.08/04.11 CP header */
int gsm411_push_cp_header(struct msgb *msg, uint8_t proto, uint8_t trans,
			     uint8_t msg_type);

#endif /* _GSM0411_UTILS_H */
