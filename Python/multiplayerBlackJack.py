import random
import time  # Added for delays

def slow_print(text, delay=1):
    """Prints text with a delay after each non-empty line (1 second by default)."""
    lines = text.split('\n')
    for line in lines:
        print(line)  # Print the line normally
        if line.strip():  # Check if line has non-whitespace content
            time.sleep(delay)  # Pause after non-empty lines

def displayMenu():
    # Using regular print for menu to avoid excessive delays (adjust if needed)
    print("\n--------------BlackJack CLI--------------")
    print("\n\n1. Rule Set")
    print("2. Play a Game")
    print("3. Exit")
    
def showRuleSet():
    slow_print("BlackJack Rules:")
    slow_print("1. Try to get as close to 21 as possible without going over.")
    slow_print("2. Number cards (2-10) = value, Face cards (J/Q/K) = 10, Ace = 1 or 11.")
    slow_print("3. Player vs Dealer (Dealer is Bot). Up to 4 players supported.")
    slow_print("4. Initial deal: 2 cards per player, 2 cards for dealer (1 hidden).")
    slow_print("5. Player turn order: Follows input name order (left to right).")
    slow_print("6. Actions per hand: Hit (draw), Stand (end), Split (if allowed).")
    slow_print("   Split allowed only with 2 same-rank cards, dealer has cards left, and hand hasn’t been split before.")
    slow_print("7. Dealer reveals hidden card after all players finish. Hits until ≥17 (soft 17 = A+6, hits on soft 17).")
    slow_print("8. Bust (total >21) = lose. Win if total > dealer (without bust). Push = tie.\n\n")
    input("Press Enter to go to main menu: ")
    
def playGame():
    # --------------------------- Step 1: Collect Player Info ---------------------------
    slow_print("\nStarting new game...")
    while True:
        num_players = input("How many players are joining? (1-4): ").strip()
        if num_players.isdigit() and 1 <= int(num_players) <= 4:
            num_players = int(num_players)
            break
        slow_print("Invalid input. Please enter a number between 1 and 4.")
    
    player_names = []
    slow_print("\nEnter player names:")
    for i in range(num_players):
        while True:
            name = input(f"Player {i+1} name: ").strip()
            if name:
                player_names.append(name)
                break
            slow_print("Name cannot be empty. Please try again.")
    
    # --------------------------- Step 2: Deck Setup & Initial Deal ---------------------------
    ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
    suits = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
    deck = [(rank, suit) for suit in suits for rank in ranks]
    random.shuffle(deck)
    
    # Track player hands (dict: name → list of hand dicts; each hand: {'cards': [...], 'is_split': bool})
    player_hands = {name: [{"cards": [], "is_split": False}] for name in player_names}
    for name in player_hands:
        hand_info = player_hands[name][0]
        # Deal 2 cards per player (initial hand)
        hand_info['cards'] = [deck.pop(), deck.pop()]
    
    dealer_hand = [deck.pop(), deck.pop()]  # Dealer's 2 cards (1 hidden initially)
    dealer_hand_revealed = False  # Dealer's hand hidden during player turns
    
    # --------------------------- Helper Functions ---------------------------
    def calculate_hand(hand_cards):
        total = 0
        aces = 0
        for card in hand_cards:
            rank = card[0]
            if rank in ['J', 'Q', 'K']:
                total += 10
            elif rank == 'A':
                total += 11
                aces += 1
            else:
                total += int(rank)
        while total > 21 and aces > 0:
            total -= 10
            aces -= 1
        is_soft = total <= 21 and aces > 0
        return total, is_soft
    
    def check_blackjack(hand_cards):
        total, _ = calculate_hand(hand_cards)
        return total == 21 and len(hand_cards) == 2
    
    def draw_card():
        if not deck:
            slow_print("Deck empty! Reshuffling...")
            deck.extend([(rank, suit) for suit in suits for rank in ranks])
            random.shuffle(deck)
        return deck.pop()
    
    def display_hands(current_player=None):
        """Display current hands with slow_print, highlighting current player's hands."""
        slow_print("\n--------------Current Hands--------------")
        # Dealer's hand (hidden or revealed)
        if dealer_hand_revealed:
            dealer_total, _ = calculate_hand(dealer_hand)
            dealer_str = ", ".join([f"{card}" for card in dealer_hand])
            slow_print(f"Dealer's Hand: [{dealer_str}] Total: {dealer_total}")
        else:
            visible = dealer_hand[0] if dealer_hand else ""
            hidden_count = len(dealer_hand) - 1
            hidden_str = ", ".join(["[Hidden]"] * hidden_count)
            dealer_str = f"{visible}, {hidden_str}" if visible else "[Hidden]"
            slow_print(f"Dealer's Hand: [{dealer_str}]")
        
        # Players' hands (highlight current player if specified)
        for name in player_names:
            hands = player_hands[name]
            if not hands:
                slow_print(f"{name}'s Hands: None")
                continue
            
            prefix = f"→ {name}'s Hand" if name == current_player else f"{name}'s Hand"
            for hand_idx, hand_info in enumerate(hands):
                hand_cards = hand_info['cards']
                total, is_soft = calculate_hand(hand_cards)
                hand_str = ", ".join([f"{card}" for card in hand_cards])
                status = " (Soft)" if is_soft else ""
                slow_print(f"{prefix} {hand_idx+1}: [{hand_str}] Total: {total}{status}")
        slow_print("-------------------------------------------")
    
    # --------------------------- Step 3: Immediate Blackjack Check ---------------------------
    dealer_blackjack = check_blackjack(dealer_hand)
    if dealer_blackjack:
        dealer_hand_revealed = True
        slow_print(f"\nDealer's Hand: {dealer_hand}")
        slow_print("Dealer has Blackjack!")
        # Check each player's hands
        for name in player_names:
            hands = player_hands[name]
            bj_hands = []
            for hand_idx, hand_info in enumerate(hands):
                if check_blackjack(hand_info['cards']):
                    bj_hands.append(hand_idx + 1)
            if bj_hands:
                slow_print(f"{name}'s Hand(s) {bj_hands} also have Blackjack → Push!")
            else:
                slow_print(f"{name} has no Blackjack → You lose!")
        input("Press Enter to continue...")
        return  # End game early
    
    # Check for immediate player Blackjacks
    any_player_bj = False
    for name in player_names:
        hands = player_hands[name]
        for hand_info in hands:
            if check_blackjack(hand_info['cards']):
                any_player_bj = True
                break
        if any_player_bj:
            break  # At least one player has BJ; proceed to check all
    
    if any_player_bj:
        dealer_hand_revealed = True  # Reveal dealer's hand for fairness
        slow_print("\nDealer reveals hidden card:")
        slow_print(f"Dealer's Hand: {dealer_hand}")
        for name in player_names:
            hands = player_hands[name]
            winning_hands = []
            for hand_idx, hand_info in enumerate(hands):
                if check_blackjack(hand_info['cards']):
                    winning_hands.append(hand_idx + 1)
            if winning_hands:
                slow_print(f"\n{name}'s Hand(s) {winning_hands} have Blackjack!")
                # Check if dealer also has BJ (handled earlier) → else, player wins
                if not dealer_blackjack:
                    slow_print(f"{name} wins with Blackjack!")
            else:
                slow_print(f"\n{name} has no Blackjack.")
        input("Press Enter to continue...")
        return
    
    # --------------------------- Step 4: Player Turns (Sequential with Enhanced Visibility) ---------------------------
    slow_print("\nStarting player turns...")
    for player_name in player_names:
        current_hands = player_hands[player_name]  # List of hand dicts for this player
        hand_idx = 0  # Track current hand being processed
        
        while hand_idx < len(current_hands):
            current_hand_info = current_hands[hand_idx]
            current_hand = current_hand_info['cards']
            total, is_soft = calculate_hand(current_hand)
            
            # Skip already busted hands
            if total > 21:
                slow_print(f"\n{player_name}'s Hand {hand_idx+1} is already bust (total {total}) → Skipping.")
                hand_idx += 1
                continue
            
            # Check for Blackjack (post-split)
            if check_blackjack(current_hand):
                slow_print(f"\n{player_name}'s Hand {hand_idx+1} has Blackjack → Automatically wins!")
                hand_idx += 1
                continue
            
            # --------------------------- Player Turn Start ---------------------------
            slow_print(f"\n\n--------------{player_name}'s Turn - Hand {hand_idx+1}--------------")
            display_hands(current_player=player_name)  # Show current state
            
            # Determine valid actions
            can_split = (len(current_hand) == 2) and (current_hand[0][0] == current_hand[1][0]) and (len(deck) >= 2) and (not current_hand_info['is_split'])
            actions = ['hit', 'stand']
            if can_split:
                actions.append('split')
            
            # Get player action with context
            while True:
                action_prompt = f"{player_name}, choose action for Hand {hand_idx+1} ({'/'.join(actions)}): "
                action = input(action_prompt).lower().strip()
                if action in actions:
                    break
                slow_print("Invalid action. Please try again.")
            
            # --------------------------- Process Action ---------------------------
            if action == 'stand':
                total, is_soft = calculate_hand(current_hand)
                slow_print(f"\n{player_name} stands on Hand {hand_idx+1}. Total: {total} {'(Soft)' if is_soft else ''}")
                hand_idx += 1  # Move to next hand
                continue
            
            elif action == 'split':
                original_hand = current_hand.copy()
                original_total, original_is_soft = calculate_hand(original_hand)
                
                # Remove original hand and draw split cards
                current_hands.pop(hand_idx)
                split_card1 = draw_card()
                split_card2 = draw_card()
                
                # Create split hands (mark as split=True)
                split_hand1 = {"cards": [original_hand[0], split_card1], "is_split": True}
                split_hand2 = {"cards": [original_hand[1], split_card2], "is_split": True}
                
                # Insert new split hands (preserves original index)
                current_hands.insert(hand_idx, split_hand1)
                current_hands.insert(hand_idx + 1, split_hand2)
                player_hands[player_name] = current_hands  # Update (redundant but explicit)
                
                # Show split outcome
                display_hands(current_player=player_name)  # Show updated hands
                sh1_total, _ = calculate_hand(split_hand1['cards'])
                sh2_total, _ = calculate_hand(split_hand2['cards'])
                slow_print(f"\nSplit successful! Original Hand {hand_idx+1} split into:")
                slow_print(f"  New Hand {hand_idx+1}: Total {sh1_total} → Cards: {split_hand1['cards']}")
                slow_print(f"  New Hand {hand_idx+2}: Total {sh2_total} → Cards: {split_hand2['cards']}")
                
                # Do NOT increment hand_idx → process first split hand next
                continue  # Skip hand_idx increment
            
            elif action == 'hit':
                slow_print(f"\n{player_name} chooses to hit on Hand {hand_idx+1}.")
                hit_loop = True
                while hit_loop:
                    # Draw new card
                    new_card = draw_card()
                    current_hand.append(new_card)
                    slow_print(f"\n{player_name} draws: {new_card}")
                    
                    # Update and display hands after hit
                    display_hands(current_player=player_name)  # Show updated state
                    
                    # Recalculate total and check bust
                    total, is_soft = calculate_hand(current_hand)
                    slow_print(f"{player_name}'s Hand {hand_idx+1} total: {total} {'(Soft)' if is_soft else ''}")
                    
                    if total > 21:
                        slow_print(f"{player_name}'s Hand {hand_idx+1} has busted (total {total})!")
                        hit_loop = False  # Exit hit loop
                        break
                    
                    # Ask to hit again (with clear context)
                    hit_again_prompt = f"{player_name}, would you like to hit again on Hand {hand_idx+1}? (y/n): "
                    while True:
                        hit_again = input(hit_again_prompt).lower().strip()
                        if hit_again in ['y', 'n']:
                            break
                        slow_print("Invalid input. Enter 'y' (yes) or 'n' (no).")
                    
                    if hit_again == 'n':
                        hit_loop = False  # Exit hit loop
                        # Confirm stand after hit
                        total, is_soft = calculate_hand(current_hand)
                        slow_print(f"\n{player_name} stands on Hand {hand_idx+1}. Total: {total} {'(Soft)' if is_soft else ''}")
                
                # Move to next hand after hit/stand
                hand_idx += 1
        
        # End of hand processing for current player
        slow_print(f"\n{player_name}'s turn completed.")
    
    # --------------------------- Step 5: Dealer's Turn (Enhanced Visibility) ---------------------------
    dealer_hand_revealed = True
    slow_print("\n\n--------------Dealer's Turn--------------")
    slow_print(f"Dealer reveals hidden card. Full hand: {dealer_hand}")
    dealer_total, dealer_is_soft = calculate_hand(dealer_hand)
    slow_print(f"Dealer's initial total: {dealer_total} {'(Soft)' if dealer_is_soft else ''}")
    
    while True:
        dealer_total, dealer_is_soft = calculate_hand(dealer_hand)
        slow_print(f"\nDealer's current hand: {dealer_hand} → Total: {dealer_total} {'(Soft)' if dealer_is_soft else ''}")
        
        # Check for bust first
        if dealer_total > 21:
            slow_print("Dealer busts!")
            break
        
        # Determine hit/stay logic (soft 17)
        if dealer_total < 17:
            must_hit = True
            reason = "Total < 17"
        elif dealer_total == 17 and dealer_is_soft:
            must_hit = True
            reason = "Soft 17 (A+6)"
        else:
            must_hit = False
            reason = "Hard 17 or higher"
        
        if must_hit:
            new_card = draw_card()
            dealer_hand.append(new_card)
            slow_print(f"\nDealer must hit ({reason}). Drawing new card: {new_card}")
            # Show updated state
            updated_total, updated_is_soft = calculate_hand(dealer_hand)
            slow_print(f"Dealer's updated hand: {dealer_hand}")
            slow_print(f"Dealer's updated total: {updated_total} {'(Soft)' if updated_is_soft else ''}")
        else:
            slow_print(f"\nDealer chooses to stand ({reason}).")
            break
    
    # --------------------------- Step 6: Final Results ---------------------------
    dealer_final_total, _ = calculate_hand(dealer_hand)
    slow_print(f"\n\n--------------Final Results--------------")
    slow_print(f"Dealer's Final Total: {dealer_final_total}")
    
    for name in player_names:
        hands = player_hands[name]
        if not hands:
            slow_print(f"\n{name}: No hands.")
            continue
        
        for hand_idx, hand_info in enumerate(hands):
            hand_cards = hand_info['cards']
            total, _ = calculate_hand(hand_cards)
            if total > 21:
                slow_print(f"\n{name}'s Hand {hand_idx+1}: Bust (total {total}) → Lose.")
                continue
            
            slow_print(f"\n{name}'s Hand {hand_idx+1}: {hand_cards} → Total: {total}")
            
            if dealer_final_total > 21:
                slow_print(f"Dealer busted! {name}'s Hand {hand_idx+1} → Win!")
            else:
                if total > dealer_final_total:
                    slow_print(f"Total ({total}) > Dealer ({dealer_final_total}) → Win!")
                elif total == dealer_final_total:
                    slow_print(f"Total ({total}) = Dealer ({dealer_final_total}) → Push!")
                else:
                    slow_print(f"Total ({total}) < Dealer ({dealer_final_total}) → Lose.")
    
    # Redisplay optional suggestions
    slow_print("\n\nOptional improvements (not yet implemented):")
    slow_print("1. Betting mechanics (players place bets before each round).")
    slow_print("2. Doubling down (double bet and draw 1 card).")
    slow_print("3. Insurance bets (bet against dealer’s Blackjack if they show an Ace).")
    input("Press Enter to return to main menu...")
    return

def main():
    while True:
        displayMenu()
        choice = input("\n\nWelcome to the BlackJack CLI! Choose a valid option from the above: ").strip()
        
        if choice.lower() in ["1", "rules", "ruleset", "rule set"]:
            showRuleSet()
            
        elif choice.lower() in ["2", "play", "play a game", "play game"]:
            playGame()
            
        elif choice.lower() in ["3", "exit"]:
            print("Goodbye!")
            break
            
        else:
            slow_print("Oops! Invalid option. Please try again.")

if __name__ == "__main__":
    main()