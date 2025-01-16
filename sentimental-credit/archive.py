'''
    # Have to use half and round it. Not great bc i need two if statments.
    length = len(number)
    length_half = round(length/2)


    extracted_numbers = []
    # Here we extract the number we are going to multiply
    # This works now

    # This part is for even numbers
    if length_half % 2 == 0:
        for i in range(1,length_half):
            extracted_numbers.insert(0,number[-2*i])

    # This one is for odd numbers
    else:
        for i in range(1,length_half+1):
            extracted_numbers.insert(0,number[-2*i])
'''


    '''
    length = len(number)
    length_half = round(length/2)
    non_extracted_numbers = number

    #This is for even numbers
    if length_half % 2 == 0:
        for i in range(1,length_half):
            non_extracted_numbers.pop(0,number[-2*i])

    # This one is for odd numbers
    else:
        for i in range(1,length_half+1):
            non_extracted_numbers.pop(0,number[-2*i])
    '''
